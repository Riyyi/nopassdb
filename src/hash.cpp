#include "hash.h"

char* Hash::GetPassword() {
    char *password;

    // Get password from user input
    password = getpass("Password: ");

    return password;
}

std::string Hash::HashPassword(char* password, char* salt) {
    std::string output;

    // Hash password
    output = crypt(password, salt);

    return output;
}

std::string Hash::OutputLength(std::string password, int start, int length) {
    // Return part of the hashing output
    password = password.substr(start, length);

    return password;
}
