#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <fstream>

class Patient : public Person {
private:
    string disease;
    string bloodGroup;
    bool admitted;

public:
    Patient();

    void inputPatient();
    void display() const override;

    bool isAdmitted() const;

    void discharge();

    void updatePatient();

     // FILE HANDLING
    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);


};

#endif
