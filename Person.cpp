//
// Created by patry on 29/10/2016.
//

#include "Person.h"
#include <fstream>

const string &Person::getName() const {
    return mName;
}

void Person::setName(const string &name) {
    mName = name;
}

const string &Person::getSurname() const {
    return mSurname;
}

void Person::setSurname(const string &surname) {
    mSurname = surname;
}

int Person::getAge() const {
    return mAge;
}

void Person::setAge(int age) {
    mAge = age;
}

Person::Person(const string &name, const string &surname, int age) : mName(name), mSurname(surname), mAge(age) {}


Person::~Person() {

}

void Person::save(ofstream &out) {
    out << this->getName() << endl;
    out << this->getSurname() << endl;
    out << this->getAge() << endl;
}

