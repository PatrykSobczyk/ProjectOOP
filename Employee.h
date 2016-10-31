//
// Created by patry on 29/10/2016.
//
#include "string"
#include "Person.h"

using namespace std;
#ifndef PROJECT_EMPLOYEE_H
#define PROJECT_EMPLOYEE_H


class Employee : virtual public Person {
private:
    int mId;
public:
    int getId() const;

    void setId(int id);

    virtual void presentYourself() override;

    Employee(const string &name, const string &surname, int age, int id);

    virtual void save(ofstream &out) override;

    virtual ~Employee();
};


#endif //PROJECT_EMPLOYEE_H
