//
// Created by patry on 29/10/2016.
//
#include "string"

using namespace std;
#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H


class Person {
private:
    string mName;
    string mSurname;
    int mAge;
public:
    virtual void presentYourself()=0;

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    int getAge() const;

    void setAge(int age);

    Person(const string &name, const string &surname, int age);

    virtual void save(ofstream &out);

    virtual ~Person();

};


#endif //PROJECT_PERSON_H
