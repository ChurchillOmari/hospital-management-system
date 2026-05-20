#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include <fstream>

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;

public:
    Doctor();

    void inputDoctor();

    void display() const override;
    void updateDoctor();
     // FILE HANDLING
    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);
};

#endif
