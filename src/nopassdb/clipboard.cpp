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
// Linux and Apple
#elif defined(__unix) || defined (__APPLE__)
int NoPassDB::CopyToClipboard(std::string string) {
    return 0;
}
#endif
