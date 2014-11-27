#ifndef HASH_H
#define HASH_H

#include <unistd.h>

#include <iostream>

class Hash
{
public:
    char *GetPassword();
    std::string HashPassword(char* password, char* salt);
    std::string OutputLength(std::string password, int start, int length);
};

#endif // HASH_H
