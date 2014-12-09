#ifndef CLIPBOARD_H
#define CLIPBOARD_H

// Windows 32-bit and 64-bit
#ifdef _WIN32
    #include <windows.h>
// Linux and Apple
#elif defined(__unix) || defined (__APPLE__)

#endif

#include <iostream>
#include <cstring>

namespace NoPassDB {
    int CopyToClipboard(std::string string);
}

#endif // CLIPBOARD_H
