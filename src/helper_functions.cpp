#include "../include/helper_functions.h"
#include <algorithm>   // ✅ Add this
#include <cctype>
#include <random>


bool HelperFunctions::isValidNumber(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string HelperFunctions::generate_random_id(int length) {
    static const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string id;
    for (int i = 0; i < length; ++i)
        id += chars[dis(gen)];
    return id;
}
