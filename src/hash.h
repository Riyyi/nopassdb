#ifndef HASH_H
#define HASH_H

#include <unistd.h>

#include <iostream>
#include <cstring>
#include <vector>

class Hash
{
public:
    char *GetPassword();
    std::string HashPassword(char* password, char* salt);
    std::string OutputLength(std::string password, int start, int length);
    std::string RemoveSpecialCharacters(std::string password);
    int StartHashing(int length, char salt[], int outputspecialchar);
};

#endif // HASH_H
