//
// Created by patry on 29/10/2016.
//

#include <iostream>
#include <fstream>
#include "Programmer.h"

int Programmer::getJobSeniority() const {
    return mJobSeniority;
}

void Programmer::setJobSeniority(int jobSeniority) {
    mJobSeniority = jobSeniority;
}

void Programmer::presentYourself() {
    cout << "I'm programmer " << "my name is " << this->getName() << " " << this->getSurname()
         << ".\nI've " << this->getAge() << " years old and " << this->getJobSeniority() << " mouths Seniority!"
         << endl;
    cout << "My id number is " << this->getId() << endl;

}

Programmer::Programmer(const string &name, const string &surname, int age, int id, int jobSeniority) : Employee(name,
                                                                                                                surname,
                                                                                                                age,
                                                                                                                id),
                                                                                                       Person(name,
                                                                                                              surname,
                                                                                                              age),
                                                                                                       mJobSeniority(
                                                                                                               jobSeniority) {}

Programmer::~Programmer() {

}

void Programmer::save(ofstream &out) {
    out << "Programmer" << endl;
    Employee::save(out);
    out << this->getJobSeniority() << endl;
}

