//
// Created by patry on 29/10/2016.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H


#include "Employee.h"

class Student : public Employee {
private:
    int mInternshipTime;
public:
    virtual void presentYourself() override;

    int getInternshipTime() const;

    void setInternshipTime(int internshipTime);

    Student(const string &name, const string &surname, int age, int id, int internshipTime);

    virtual void save(ofstream &out) override;

    virtual ~Student();
};


#endif //PROJECT_STUDENT_H
