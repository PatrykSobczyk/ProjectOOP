//
// Created by patry on 29/10/2016.
//

#ifndef PROJECT_ACCOUNT_H
#define PROJECT_ACCOUNT_H


#include "Employee.h"

class Account {
private:
    Employee *mOwner;
    double mBalance;
public:

    void showBalance() const;

    void deposit(double amount);

    void withdraw(double amount);

    void save(ofstream &out);

    Employee *getOwner() const;

    void setOwner(Employee *owner);

    double getBalance() const;

    void setBalance(double balance);

    Account(Employee *owner, double balance);

    Account &operator-=(const double &value);

    Account &operator+=(const double &value);

};


#endif //PROJECT_ACCOUNT_H
