//
// Created by patry on 29/10/2016.
//



#ifndef PROJECT_CASH_H
#define PROJECT_CASH_H

#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Account.h"
#include "Programmer.h"
#include "Student.h"


using namespace std;

template<class T>
class Cash {
private:
    multimap<int, T> mContainer;
    vector<int> mIdOwners;
    vector<int> mContent;
public:
    void add(int id, T obj) {
        mContainer.insert(pair<int, T>(id, obj));
    }

    const multimap<int, T> &getContainer() const {
        return mContainer;
    }

    void setContainer(const multimap<int, T> &container) {
        mContainer = container;
    }

    const vector<int> &getIdOwners() const {
        return mIdOwners;
    }

    void setIdOwners(const vector<int> &idOwners) {
        mIdOwners = idOwners;
    }

    const vector<int> &getContent() const {
        return mContent;
    }

    void setContent(const vector<int> &content) {
        mContent = content;
    }


    void showAll() {
        typename multimap<int, T>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            cout << it->first << " " << it->second.getContent() << endl;
        }
    }

    Cash(const multimap<int, T> &container) : mContainer(container) {}

    Cash() { mContainer = multimap<int, T>(); }

};

template<>
class Cash<Account> {
private:
    multimap<int, Account *> mContainer;
public:
    void showAll() {
        cout << "W kasie mamy nastepujace konta :" << endl;
        cout << "ID Imie Nazwisko Saldo" << endl;
        typename multimap<int, Account *>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            cout << it->first << " " << it->second->getOwner()->getName() << " "
                 << it->second->getOwner()->getSurname() << " "
                 << it->second->getBalance() << endl;
        }
    }

    double getAllAccountBalance() {
        double sum = 0;
        typename multimap<int, Account *>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            sum += it->second->getBalance();
        }
        return sum;
    }

    void add(Account *account) {
        mContainer.insert(pair<int, Account *>(account->getOwner()->getId(), account));
        save();
    }

    Account *getAccount(int idOwner) {
        typename multimap<int, Account *>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            if (it->first == idOwner) {
                return it->second;
            }
        }
        if (it == mContainer.end()) {
            cout << "Ta osoba niestety nie ma konta w naszej kasie.";
        }
    }

    void deleteAccount(int idOwner) {
        typename multimap<int, Account *>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            if (it->first == idOwner) {
                if (it->second->getBalance() == 0) {
                    mContainer.erase(idOwner);
                    cout << "Konto zostalo usuniete.";
                    save();
                    return;
                } else {
                    cout << "Nie mozemy usunac konta, poniewaz saldo !=0. " << it->second->getBalance();
                    return;
                }
            }
        }
        if (it == mContainer.end()) {
            cout << "Ta osoba niestety nie ma konta w naszej kasie.";
        }
    }

    void transfer(int idLender, int idBorrower, double amount) {
        if (idLender == idBorrower) {
            cout << "Nie mozesz sam sobie pozyczyc.";
            return;
        }
        typename multimap<int, Account *>::iterator it;
        typename multimap<int, Account *>::iterator it2;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            if (it->first == idLender) {
                for (it2 = mContainer.begin(); it2 != mContainer.end(); it2++) {
                    if (it2->first == idBorrower) {
                        if (Student *s = dynamic_cast<Student *>( it2->second->getOwner())) {
                            cout << "Nie pozyczamy pieniedzy studentowi!!!";
                            break;
                        } else if (Programmer *p = dynamic_cast<Programmer *>( it2->second->getOwner())) {
                            if (it->second->getBalance() >= amount) {
                                *it->second -= amount;
                                *it2->second += amount;
                                cout << "Transfer udany.";
                                save();
                                break;
                            } else {
                                cout << "Osoba, ktora ma id " << idLender << " nie moze pozyczyc tylu pieniedzy!";
                                break;
                            }
                        }
                    }
                }
            }
        }

    }

    void save() {
        ofstream out;
        out.open("cash.txt");
        typename multimap<int, Account *>::iterator it;
        for (it = mContainer.begin(); it != mContainer.end(); it++) {
            it->second->save(out);
        }
    }

    void read() {
        ifstream input;
        try {
            input.open("cash.txt");
            string typeEmployee, name, surname;
            int id, age, additionalField;
            double accountBalance;
            if (input.good()) {
                while (!input.eof()) {
                    input >> typeEmployee >> id >> name >> surname >> age;
                    if (input.eof()) {
                        break;
                    }
                    cout << typeEmployee << endl;
                    if (typeEmployee == "Programmer") {
                        input >> additionalField;
                        input >> accountBalance;
                        Programmer *programmer = new Programmer(name, surname, age, id, additionalField);
                        Account *account = new Account(programmer, accountBalance);
                        add(account);
                    } else if (typeEmployee == "Student") {
                        input >> additionalField;
                        input >> accountBalance;
                        Student *student = new Student(name, surname, age, id, additionalField);
                        Account *account = new Account(student, accountBalance);
                        add(account);
                    } else if (typeEmployee == "Employee") {
                        input >> accountBalance;
                        Employee *employee = new Employee(name, surname, age, id);
                        Account *account = new Account(employee, accountBalance);
                        add(account);
                    }
                }
                input.close();
            } else {
                throw "Plik nie istnieje lub jest pusty. Koniecznie dodaj jakies konto!";
            }
            return;
        } catch (const char *error) {
            cerr << error << '\n';
            return;
        }
    }
};


#endif //PROJECT_CASH_H
