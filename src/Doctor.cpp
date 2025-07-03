#include "../include/doctor.h"

Doctor::Doctor(const std::string& id, const std::string& name, const std::string& specialization)
    : id(id), name(name), specialization(specialization) {}

std::string Doctor::get_id() const { return id; }
std::string Doctor::get_name() const { return name; }
std::string Doctor::get_specialization() const { return specialization; }
void Doctor::set_name(const std::string& new_name) { name = new_name; }
void Doctor::set_specialization(const std::string& new_spec) { specialization = new_spec; }




