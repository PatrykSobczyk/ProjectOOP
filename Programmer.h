//
// Created by patry on 29/10/2016.
//

#ifndef PROJECT_PROGRAMMER_H
#define PROJECT_PROGRAMMER_H


#include "Employee.h"

class Programmer : public Employee {
private:
    int mJobSeniority;
public:
    int getJobSeniority() const;

    void setJobSeniority(int jobSeniority);

    virtual void presentYourself() override;

    Programmer(const string &name, const string &surname, int age, int id, int jobSeniority);

    virtual void save(ofstream &out) override;

    virtual ~Programmer();
};


#endif //PROJECT_PROGRAMMER_H
