#include "../include/billing.h"
using namespace std;

Billing::Billing(const string& billing_id,
                 const string& patient_id,
                 const string& appointment_id,
                 double consultation_fee,
                 double medicine_charge,
                 double other_charge)
    : billing_id(billing_id),
      patient_id(patient_id),
      appointment_id(appointment_id),
      consultation_fee(consultation_fee),
      medicine_charge(medicine_charge),
      other_charge(other_charge),
      isPaid(false) {}

double Billing::getTotal() const {
    return consultation_fee + medicine_charge + other_charge;
}

bool Billing::paid() const {
    return isPaid;
}

void Billing::markPaid() {
    isPaid = true;
}

void Billing::displayBill() const {
    cout << "\n----- Final Bill -----\n";
    cout << "Patient ID      : " << patient_id << endl;
    cout << "Appointment ID  : " << appointment_id << endl;
    cout << "Consultation Fee: Rs. " << consultation_fee << endl;
    cout << "Medicine Charge : Rs. " << medicine_charge << endl;
    cout << "Other Charges   : Rs. " << other_charge << endl;
    cout << "Total Amount    : Rs. " << getTotal() << endl;
    cout << "Status          : " << (isPaid ? "Paid" : "Pending") << endl;
    cout << "----------------------\n";
}

string Billing::getPatientID() const {
    return patient_id;
}

string Billing::getAppointmentID() const {
    return appointment_id;
}