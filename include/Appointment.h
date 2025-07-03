#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
using namespace std;

class Appointment {
private:
    string appointment_id;
    string patient_id;
    string doctor_id;
    string date;

public:
    Appointment() {} 
    Appointment(const string& appointment_id,
                const string& patient_id,
                const string& doctor_id,
                const string& date);

    string get_appointment_id() const;
    string get_patient_id() const;
    string get_doctor_id() const;
    string get_date() const;
};

#endif

