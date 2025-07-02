#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>
#include <cctype>
#include <algorithm>

class HelperFunctions {
public:
    // Check if a string is a valid integer number
    static bool isValidNumber(const std::string& str) {
        return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
    }

    // Generate unique ID (optional: could be used for backup IDs)
    static std::string generate_random_id(int length = 6) {
        std::string id = "U";
        for (int i = 0; i < length; ++i)
            id += '0' + rand() % 10;
        return id;
    }
};

#endif
