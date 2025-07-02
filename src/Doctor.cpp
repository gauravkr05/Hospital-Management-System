#include "../include/doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor(const string& name, const string& specialization, const string& id)
    : User(id, name), specialization(specialization) {}

void Doctor::viewAppointments() const {
    cout << "\nViewing appointments for Dr. " << name << " (ID: " << user_id << ")\n";
    cout << "(Simulation) Appointments would be listed here.\n";
}

void Doctor::treatPatient(const string& appointmentId) {
    cout << "\nTreating patient for Appointment ID: " << appointmentId << endl;
    cout << "(Simulation) Treatment has been recorded.\n";
}

string Doctor::getSpecialization() const {
    return specialization;
}

void Doctor::displayInfo() const {
    cout << "Doctor Name       : " << name << endl;
    cout << "Doctor ID         : " << user_id << endl;
    cout << "Specialization    : " << specialization << endl;
}

string Doctor::getRole() const {
    return "Doctor";
}


