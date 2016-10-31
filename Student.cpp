//
// Created by patry on 29/10/2016.
//

#include <iostream>
#include <fstream>
#include "Student.h"

void Student::presentYourself() {
    cout << "I'm student " << "my name is " << this->getName() << " " << this->getSurname()
         << ".\nI've " << this->getAge() << " years old and " << this->getInternshipTime() << " mouths Internship!"
         << endl;
    cout << "My id number is " << this->getId() << endl;
}

int Student::getInternshipTime() const {
    return mInternshipTime;
}

void Student::setInternshipTime(int internshipTime) {
    mInternshipTime = internshipTime;
}

Student::Student(const string &name, const string &surname, int age, int id, int internshipTime) : Employee(name,
                                                                                                            surname,
                                                                                                            age,
                                                                                                            id),
                                                                                                   Person(name, surname,
                                                                                                          age),
                                                                                                   mInternshipTime(
                                                                                                           internshipTime) {}

Student::~Student() {

}

void Student::save(ofstream &out) {
    out << "Student" << endl;
    Employee::save(out);
    out << this->getInternshipTime() << endl;
}
