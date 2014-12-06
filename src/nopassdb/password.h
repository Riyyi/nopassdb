#ifndef PASSWORD_H
#define PASSWORD_H

// Windows 32-bit and 64-bit
#ifdef _WIN32
    #include <string>
    #include <windows.h>
// Linux and Apple
#elif defined(__unix) || defined (__APPLE__)
    #include <termios.h>
    #include <unistd.h>
#endif

#include <iostream>

namespace NoPassDB {
    std::string GetPassword(std::string prompt);
}

#endif // PASSWORD_H
