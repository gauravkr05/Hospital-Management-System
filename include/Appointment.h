#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
private:
    std::string appointment_id;
    std::string patient_id;
    std::string doctor_id;
    std::string date;
    std::string time;
    bool isAssigned;

public:
    Appointment(const std::string& appointment_id,
                const std::string& patient_id,
                const std::string& date,
                const std::string& time);

    std::string getAppointmentID() const;
    std::string getPatientID() const;
    std::string getDoctorID() const;
    std::string getDate() const;
    std::string getTime() const;
    bool assigned() const;

    void assignDoctor(const std::string& doctor_id);

    void displayAppointment() const;
};

#endif
