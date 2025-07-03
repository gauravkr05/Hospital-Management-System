#include "../include/appointment.h"
using namespace std;

Appointment::Appointment(const string& appointment_id,  const string& patient_id,
                         const string& doctor_id, const string& date)

 : appointment_id(appointment_id), patient_id(patient_id), doctor_id(doctor_id), date(date) {}

 string Appointment::get_appointment_id() const { return appointment_id; }
string Appointment::get_patient_id() const { return patient_id; }
string Appointment::get_doctor_id() const { return doctor_id; }
string Appointment::get_date() const { return date; }
