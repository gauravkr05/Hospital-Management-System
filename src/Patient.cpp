#include "../include/patient.h"
#include <iostream>
using namespace std;

Patient::Patient(const string& name, int age, const string& id)
    : User(id, name), age(age), diagnosis("Not diagnosed yet") {}

void Patient::setDiagnosis(const string& diag) {
    diagnosis = diag;
}

string Patient::getDiagnosis() const {
    return diagnosis;
}

int Patient::getAge() const {
    return age;
}

void Patient::displayInfo() const {
    cout << "Patient Name   : " << name << endl;
    cout << "Patient ID     : " << user_id << endl;
    cout << "Age            : " << age << endl;
    cout << "Diagnosis      : " << diagnosis << endl;
}

string Patient::getRole() const {
    return "Patient";
}

