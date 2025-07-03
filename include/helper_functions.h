#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>

class HelperFunctions {
public:
    static bool isValidNumber(const std::string& str);
    static std::string generate_random_id(int length = 6);
};

#endif

