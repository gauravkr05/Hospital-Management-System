#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "user.h"

class Patient : public User {
private:
    int age;
    std::string diagnosis;

public:
    Patient(const std::string& name, int age, const std::string& id = "");

    void setDiagnosis(const std::string& diag);
    std::string getDiagnosis() const;
    int getAge() const;

    void displayInfo() const override;
    std::string getRole() const override;
};

#endif

