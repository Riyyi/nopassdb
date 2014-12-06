#include "hash.h"

std::string NoPassDB::HashPassword(std::string password, std::string salt) {
    std::string output;

    // Hash password
    output = sw::sha512::calculate(password + salt);
    sw::base64::encode(output, output);

    return output;
}

std::string NoPassDB::OutputLength(std::string password, int start, int length) {
    // Return part of the hashing output
    password = password.substr(start, length);

    return password;
}

int NoPassDB::StartHashing(std::string password, int length, std::string salt) {
    int start = salt.length();

    // Hash password
    std::string output;
    output = NoPassDB::HashPassword(password, salt);

    output = NoPassDB::OutputLength(output, start, length);
    #ifdef _WIN32
    std::cout << output;
    #else
    std::cout << output << std::endl;
    #endif


//    #include <Windows.h>
//    // Copy password to clipboard (WindowsAPI)
//    int clipboardLength = std::strlen(output.c_str()) + 1;
//    HGLOBAL glob = GlobalAlloc(GMEM_FIXED,clipboardLength);
//    memcpy(glob,output.c_str(),clipboardLength);

//    OpenClipboard(0);
//    EmptyClipboard();
//    SetClipboardData(CF_TEXT,glob);
//    CloseClipboard();

    return 0;
}
