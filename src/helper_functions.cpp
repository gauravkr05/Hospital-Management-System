#include "../include/helper_functions.h"
#include <cstdlib>   // for rand()
#include <ctime>     // for time()

// Make sure to seed the RNG once (you can call this in main or constructor)
static bool seeded = false;

bool HelperFunctions::isValidNumber(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string HelperFunctions::generate_random_id(int length) {
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    std::string id = "U";
    for (int i = 0; i < length; ++i) {
        id += '0' + rand() % 10;
    }
    return id;
}
