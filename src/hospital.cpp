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

void Hospital::add_appointment(const string& patient_id, const string& doctor_id, const string& date) {
    string appointment_id = "A" + to_string(++appointment_counter);
    appointments[appointment_id] = Appointment(appointment_id, patient_id, doctor_id, date);
    cout << "Appointment ID " << appointment_id << " booked for Patient " << patient_id
         << " with Doctor " << doctor_id << " on " << date << ".\n";
}

bool Hospital::assign_doctor_to_patient(const string& patient_id, const string& doctor_id) {
    if (patients.find(patient_id) == patients.end()) {
        cout << "Patient ID not found.\n";
        return false;
    }
    if (doctors.find(doctor_id) == doctors.end()) {
        cout << "Doctor ID not found.\n";
        return false;
    }
    patient_to_doctor_map[patient_id] = doctor_id;
    cout << "Doctor " << doctor_id << " assigned to Patient " << patient_id << ".\n";
    return true;
}


void Hospital::view_doctor_schedule(const string& doctor_id) const {
    bool found = false;
    for (const auto& entry : appointments) {
        const Appointment& appointment = entry.second;
        if (appointment.get_doctor_id() == doctor_id) {
            cout << "Appointment ID: " << appointment.get_appointment_id()
                 << ", Patient ID: " << appointment.get_patient_id()
                 << ", Date: " << appointment.get_date() << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No appointments found for Doctor " << doctor_id << ".\n";
    }
}
