#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <map>
#include <string>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
using namespace std;

class Hospital {
private:
    map<string, Patient> patients;
    map<string, Doctor> doctors;
    map<string, Appointment> appointments;
    map<string, string> patient_to_doctor_map;
    int appointment_counter = 0;
    int patient_counter = 0;
    int doctor_counter = 0;
    Hospital();

public:
    static Hospital& getInstance();
    void add_patient(const string& name, int age);
    bool remove_patient(const string& id);
    void add_doctor(const string& name, const std::string& spec);
    bool remove_doctor(const string& id);
    void add_appointment(const string& patient_id, const string& doctor_id, const string& date);
    bool assign_doctor_to_patient(const string& patient_id, const string& doctor_id);
    void view_doctor_schedule(const string& doctor_id) const;
    void view_all_treatments() const;
    void add_billing(const string& patient_id, double base_amount);
};

#endif