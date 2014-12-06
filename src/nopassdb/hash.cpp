#include "hash.h"

std::string NoPassDB::HashPassword(std::string password, std::string salt) {
    std::string output;

    // Hash password
    output = sw::sha512::calculate(password);
    sw::base64::encode(output, output);

    return output;
}

std::string NoPassDB::OutputLength(std::string password, int start, int length) {
    // Return part of the hashing output
    password = password.substr(start, length);

    return password;
}

std::string NoPassDB::RemoveSpecialCharacters(std::string password) {
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

int NoPassDB::StartHashing(std::string password, int length, std::string salt, int outputspecialchar) {
    int start = salt.length();

    // Hash password
    std::string output;
    output = HashPassword(password, salt);

    if (!outputspecialchar) {
        output = RemoveSpecialCharacters(output);
    }

    output = OutputLength(output, start, length);
    std::cout << output;

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
