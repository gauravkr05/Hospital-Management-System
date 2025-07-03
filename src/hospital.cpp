#include "../include/hospital.h"
#include <iostream>
using namespace std;

Hospital::Hospital() {}

Hospital& Hospital::getInstance() {
    static Hospital instance;
    return instance;
}

void Hospital::add_patient(const string& name, int age) {
    string id = "P" + to_string(++patient_counter);
    patients[id] = Patient(id, name, age);
    cout << "Assigned ID: " << id << endl;
}

bool Hospital::remove_patient(const string& id) {
    return patients.erase(id) > 0;
}

void Hospital::add_doctor(const string& name, const string& spec) {
    string id = "D" + to_string(++doctor_counter);
    doctors[id] = Doctor(id, name, spec);
    cout << "Assigned ID: " << id << endl;
}

bool Hospital::remove_doctor(const string& id) {
    return doctors.erase(id) > 0;
}

