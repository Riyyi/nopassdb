#include "password.h"

// Windows 32-bit and 64-bit
#ifdef _WIN32
std::string NoPassDB::GetPassword(std::string prompt) {
    const char BACKSPACE = 8;
    const char RETURN = 13;

    std::string password;
    unsigned char ch = 0;

    std::cout << prompt;

    DWORD con_mode;
    DWORD dwRead;

    HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

    GetConsoleMode(hIn, &con_mode);
    SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch != RETURN) {
        if(ch == BACKSPACE) {
            if(password.length() != 0) {
                password.resize(password.length() - 1);
            }
        }
        else {
             password += ch;
        }
    }

    std::cout << std::endl;
    return password;
}
// Linux and Apple
#elif defined(__unix) || defined (__APPLE__)
// Get input from terminal without displaying the input
int Getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

// Listen to user input until the `enter` key has been pressed
std::string NoPassDB::GetPassword(std::string prompt) {
    const char BACKSPACE = 127;
    const char RETURN = 10;

    std::string password;
    unsigned char ch = 0;

    std::cout << prompt;

    while ((ch = Getch()) != RETURN) {
        if (ch == BACKSPACE) {
            if (password.length() != 0) {
                password.resize(password.length() - 1);
            }
        }
        else {
            password += ch;
        }
    }

    std::cout << std::endl;
    return password;
}
#endif
