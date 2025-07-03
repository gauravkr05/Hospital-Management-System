#include "../include/patient.h"

Patient::Patient(const std::string& id, const std::string& name, int age)
    : id(id), name(name), age(age) {}

std::string Patient::get_id() const { return id; }
std::string Patient::get_name() const { return name; }
int Patient::get_age() const { return age; }
void Patient::set_name(const std::string& new_name) { name = new_name; }
void Patient::set_age(int new_age) { age = new_age; }
