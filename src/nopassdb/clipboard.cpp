#include "clipboard.h"

// Windows 32-bit and 64-bit
#ifdef _WIN32
int NoPassDB::CopyToClipboard(std::string string) {
    // Copy password to clipboard (WindowsAPI)
    int clipboardLength = string.length() + 1;

    HGLOBAL glob = GlobalAlloc(GMEM_FIXED, clipboardLength);
    std::memcpy(glob, string.c_str(), clipboardLength);

    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT,glob);
    CloseClipboard();

    return 0;
}
// Linux
#elif defined(__unix)
int NoPassDB::CopyToClipboard(std::string string) {
    // Command example: echo "password" | xsel -b -i
    //                  echo "password" | xclip --clipboard --input
    string = "echo \"" + string + "\" | xsel -i -b";
    system(string.c_str());

    return 0;
}
// Apple
#elif defined(__APPLE__)
int NoPassDB::CopyToClipboard(std::string string) {
    // Command example: echo "password" | pbcopy
    string = "echo \"" + string + "\" | pbcopy";
    system(string.c_str());

    return 0;
}
#endif
