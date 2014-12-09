#include "hash.h"

std::string NoPassDB::HashPassword(std::string password, std::string salt) {
    std::string output;

    // Hash password
    output = sw::sha512::calculate(password + salt);
    sw::base64::encode(output, output);

    return output;
}

std::string NoPassDB::OutputLength(std::string password, int length) {
    // Return part of the hashing output
    password = password.substr(0, length);

    return password;
}

int NoPassDB::StartHashing(std::string &password, int length, std::string salt) {
    // Hash password
    password = NoPassDB::HashPassword(password, salt);

    // Trim to desired length
    password = NoPassDB::OutputLength(password, length);
#ifdef _WIN32
    std::cout << password;
#else
    std::cout << password << std::endl;
#endif

    return 0;
}
