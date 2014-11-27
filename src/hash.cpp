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

std::string Hash::RemoveSpecialCharacters(std::string password) {
    // Special characters to remove
    std::string specialchararcters[] = {"/", "."};

    // Removes them here
    for (std::string sc : specialchararcters) {
        int pos = 0;
        while((pos = password.find(sc, pos)) != std::string::npos) {
                 password.replace(pos, 1, "");

                 if (!password.find("/", pos + 1)) {
                     pos ++;
                 }
        }
    }

    return password;
}

int Hash::StartHashing(int length, char salt[], int outputspecialchar) {
    // Get users password
    char *password;
    password = GetPassword();

    int start = std::strlen(salt);

    // Hash password
    std::string output;
    output = HashPassword(password, salt);

    if (!outputspecialchar) {
        output = RemoveSpecialCharacters(output);
    }

    output = OutputLength(output, start, length);

    std::cout << output << std::endl;

    return 0;
}
