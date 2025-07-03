#include "../include/billing.h"

Billing::Billing(const std::string& billing_id,
                 const std::string& patient_id,
                 const std::string& date,
                 double consultation_fee,
                 double medicine_fee,
                 double other_charges)
    : billing_id(billing_id), patient_id(patient_id), date(date),
      consultation_fee(consultation_fee), medicine_fee(medicine_fee), other_charges(other_charges) {}

double Billing::get_total() const {
    return consultation_fee + medicine_fee + other_charges;
}
