#include <iostream>
#include <cstring>
#include <vector>

#include "headers.h"

int main(int argc, char ** argv) {
    // VARIABLE DECLARATION
        // Default output length
        int length = 20; // -l --length [number]

        // Declare salt variable
        char salt[] = "$6$[ENTER YOUR SALT HERE]$";

        // Help argument
        int help; // -h --help

    // Construct GetOpt object by passing argc and argv arguments
    GetOpt::GetOpt_pp args(argc, argv);

    // Exceptions set to invalid format
    args.exceptions(std::ios::failbit);

    // Process arguments
    help = args >> GetOpt::OptionPresent('h', "help");

    try {
        args >> GetOpt::Option('l', "length", length);
    }
    catch (GetOpt::GetOptEx) {
        std::cerr << "nopassdb: value given to option -l --length wasn't a number." << std::endl;

        return 0;
    }

    if (args.options_remain()) {
        std::cout << "nopassdb: '" << args.options_remain() << "' is not a nopassdb command. See 'nopassdb --help'." << std::endl;

        return 0;
    }

    // Go through options
    if (help) {
        ArgHelp arghelp;
        arghelp.Main();

        return 0;
    }
    else {
        // Construct password hashing object
        Hash hash;

        // Get users password
        char *password;
        password = hash.GetPassword();

        int start = std::strlen(salt);

        // Hash password
        std::string output;
        output = hash.HashPassword(password, salt);

        output = hash.OutputLength(output, start, length);
        std::cout << output << std::endl;
    }

    return 0;
}
