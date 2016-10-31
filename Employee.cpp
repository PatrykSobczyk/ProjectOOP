//
// Created by patry on 29/10/2016.
//

#include <iostream>
#include <fstream>
#include "Employee.h"

int Employee::getId() const {
    return mId;
}

void Employee::setId(int id) {
    mId = id;
}

Employee::Employee(const string &name, const string &surname, int age, int id) : Person(name, surname, age), mId(id) {}

Employee::~Employee() {

}

void Employee::presentYourself() {
    cout << "I'm employer in this company! :)";
}

void Employee::save(ofstream &out) {
    out << this->getId() << endl;
    Person::save(out);

}


