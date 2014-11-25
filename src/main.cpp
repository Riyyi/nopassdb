#include <unistd.h>

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "arghandle.h"

// Default output length
int length = 20;

// Declare salt variable
char salt[] = "$6$[ENTER YOUR SALT HERE]$";

int main(int argc, char ** argv) {
    std::vector<std::string> arguments(argv, argv + argc);

    for(std::string& s : arguments) {
        //std::cout << s << std::endl;

        //std::vector<int> test = s;
    }

    // Exit program when given any wrong arguments
    if (!argHandle(argc, argv)) {
        return 0;
    }

    // Get users password
    char *password;
    password = getpass("Password: ");

    int start = std::strlen(salt);

    // Hash, cut, output password
    std::string output = crypt(password, salt);
    output = output.substr(start, length);
    std::cout << output << std::endl;

    return 0;
}
