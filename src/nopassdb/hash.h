#ifndef HASH_H
#define HASH_H

// Linux and Apple
#if defined(__unix) || defined (__APPLE__)
    #include <unistd.h>
#endif

#include <iostream>
#include <cstring>

namespace NoPassDB {
    std::string HashPassword(std::string password, std::string salt);
    std::string OutputLength(std::string password, int length);
    int StartHashing(std::string &password, int length, std::string salt);
}

#include "../../lib/base64.hh"
#include "../../lib/sha512.hh"

#endif // HASH_H
