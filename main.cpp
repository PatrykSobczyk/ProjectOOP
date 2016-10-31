#include <iostream>
#include "Programmer.h"
#include "Account.h"
#include "Student.h"
#include "Cash.cpp"

using namespace std;
Cash<Account> *cash = new Cash<Account>();

void newAccount();

int main() {
    cash->read();
    bool isRunning = true;
    while (isRunning) {
        int mNumberOfDecision;
        cout << "1 - Dodaj konto." << endl;
        cout << "2 - Usun konto." << endl;
        cout << "3 - Edytuj saldo konta." << endl;
        cout << "4 - Wykonaj przelew miedzy kontami." << endl;
        cout << "5 - Wyswietl stan kasy." << endl;
        cout << "6 - Wyswietl salda wszystkich kont." << endl;
        cout << "7 - Zakoncz program" << endl;
        cin >> mNumberOfDecision;

        switch (mNumberOfDecision) {
            case 1:
                newAccount();
                break;
            case 2:
                cash->showAll();
                cout << "Wpisz id osoby, ktorej konto chcesz usunac: ";
                int id;
                cin >> id;
                cash->deleteAccount(id);
                break;
            case 3:
                cash->showAll();
                cout << "Kogo konto edytujemy: ";
                int id2;
                double amount;
                cin >> id2;
                cout << endl;
                cout << "Wpisz kwote: ";
                cin >> amount;
                *cash->getAccount(id2) += amount;
                cash->save();
                break;
            case 4:
                cash->showAll();
                int idL;
                cout << "Kto chce przelac: ";
                cin >> idL;
                cout << endl;
                cout << "Komu chce przelac: ";
                int idB;
                cin >> idB;
                cout << endl;
                cout << "Jaka kwota: ";
                double amount2;
                cin >> amount2;
                cout << endl;
                cash->transfer(idL, idB, amount2);
                break;
            case 5:
                cout << "Stan kasy to: " << cash->getAllAccountBalance() << endl;
                break;
            case 6:
                cash->showAll();
                break;
            case 7:
                isRunning = false;
                break;
            default:
                cout << "Podales/as zly numer. Podaj go jeszcze raz" << endl;
                cin >> mNumberOfDecision;
                break;
        }
    }
    return 0;
}

void newAccount() {
    cout << "Kto bedzie wlascicielem konta?";
    cout << "1. Programista" << endl;
    cout << "2. Stazysta" << endl;
    cout << "Inny wybor. Przerwij" << endl;
    int typeEmployee;
    string name, surname;
    int age, bonus, id;
    double balance;
    cin >> typeEmployee;
    if (typeEmployee < 1 || typeEmployee > 2) {
        return;
    }
    cout << "Wpisz imie wlasciciela konta: ";
    cin >> name;
    cout << endl;
    cout << "Wpisz nazwisko wlasciciela konta: ";
    cin >> surname;
    cout << endl;
    cout << "Wpisz wiek wlasciciela konta: ";
    cin >> age;
    cout << endl;
    cout << "Wpisz numer id wlasciciela konta: ";
    cin >> id;
    cout << endl;
    cout << "Wpisz saldo poczatkowe konta: ";
    cin >> balance;
    cout << endl;
    Account *account;
    Programmer *programmer;
    Student *student;
    switch (typeEmployee) {
        case 1:
            cout << "Wpisz ilosc lat pracy programisty: ";
            cin >> bonus;
            cout << endl;
            programmer = new Programmer(name, surname, age, id, bonus);
            account = new Account(programmer, balance);
            cash->add(account);
            break;
        case 2:
            cout << "Wpisz ilosc miesiecy stazu studenta: ";
            cin >> bonus;
            cout << endl;
            student = new Student(name, surname, age, id, bonus);
            account = new Account(student, balance);
            cash->add(account);
            break;
        default:
            return;
    }

}