#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <iostream>

class Billing {
private:
    std::string billing_id;
    std::string patient_id;
    std::string appointment_id;
    double consultation_fee;
    double medicine_charge;
    double other_charge;
    bool isPaid;

public:
    Billing(const std::string& billing_id,
            const std::string& patient_id,
            const std::string& appointment_id,
            double consultation_fee,
            double medicine_charge = 0.0,
            double other_charge = 0.0);

    double getTotal() const;
    bool paid() const;
    void markPaid();

    void displayBill() const;
    std::string getPatientID() const;
    std::string getAppointmentID() const;
};

#endif
