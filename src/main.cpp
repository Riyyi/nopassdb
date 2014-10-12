#include <unistd.h>
#include <string.h>

#include <iostream>
#include <sstream>

int main(int argc, char ** argv) {
    // Default output length
    int length = 20;

    // Declare salt variable
    char salt[] = "$6$[ENTER YOUR SALT HERE]$";

    // If there is an argument set
    if (argc >= 2) {
        std::stringstream buffer(argv[1]);
        int x;

        // Check if argument is an integer
        if(!(buffer >> x)) {
            std::cout << "Given argument wasn't a number" << std::endl;
            return 0;
        } else {
            if(std::to_string(x) != argv[1]) {
                std::cout << "Given argument wasn't a number" << std::endl;
                return 0;
            }
        }

        length = x;
    }

    // Get users password
    char *password;
    password = getpass("Password: ");

    int start = strlen(salt);

    // Hash, cut, output password
    std::string output = crypt(password, salt);
    output = output.substr(start, length);
    std::cout << output << std::endl;

    return 0;
}
