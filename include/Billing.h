#ifndef BILLING_H
#define BILLING_H

#include <string>
using namespace std;

class Billing {
private:
    string billing_id;
    string patient_id;
    string date;
    double consultation_fee;
    double medicine_fee;
    double other_charges;

public:
    // Billing() : amount(0), tax(0), total(0) {} 
    Billing(const string& billing_id,
            const string& patient_id,
            const string& date,
            double consultation_fee,
            double medicine_fee,
            double other_charges);

    double get_total() const;
};

#endif
