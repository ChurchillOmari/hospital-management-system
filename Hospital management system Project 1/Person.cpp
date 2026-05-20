#include "Person.h"

Person::Person() {

    id = 0;
    name = "";
    age = 0;
    gender = "";
    phone = "";
}

void Person::setBasicDetails(
    int i,
    string n,
    int a,
    string g,
    string p
) {

    id = i;
    name = n;
    age = a;
    gender = g;
    phone = p;
}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}
