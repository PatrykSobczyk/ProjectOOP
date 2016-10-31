//
// Created by patry on 29/10/2016.
//

#include <fstream>
#include <iomanip>
#include "Account.h"
#include "Programmer.h"
#include "Student.h"

void Account::deposit(double amount) {
    mBalance += amount;
}

void Account::withdraw(double amount) {
    mBalance -= amount;
}


void Account::save(ofstream &out) {
    if (Student *s = dynamic_cast<Student *>( mOwner )) {
        s->save(out);
    } else if (Programmer *p = dynamic_cast<Programmer *>( mOwner )) {
        p->save(out);
    }
    out << this->getBalance() << endl;

}

Employee *Account::getOwner() const {
    return mOwner;
}

void Account::setOwner(Employee *owner) {
    mOwner = owner;
}

double Account::getBalance() const {
    return mBalance;
}

void Account::setBalance(double balance) {
    mBalance = balance;
}

Account::Account(Employee *owner, double balance) : mOwner(owner), mBalance(balance) {}

Account &Account::operator-=(const double &value) {
    this->mBalance -= value;
    return *this;
}

Account &Account::operator+=(const double &value) {
    this->mBalance += value;
    return *this;
}


