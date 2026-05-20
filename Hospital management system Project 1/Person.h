#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string gender;
    string phone;

public:
    Person();

    void setBasicDetails(
        int id,
        string name,
        int age,
        string gender,
        string phone
    );

    int getId() const;
    string getName() const;

    virtual void display() const = 0;

    virtual ~Person() {}
};



#endif // PERSON_H_INCLUDED
