#include "main.h"

#include <iostream>
#include <vector>

int main(int argc, char ** argv) {
    // Variable declaration
    int length;
    std::string salt;

    // Create config if none could be found
    if (!NoPassDB::CheckConfig(length, salt)) {
        salt = NoPassDB::GetPassword("Enter the Salt you want to use: ");
        NoPassDB::CreateConfig(salt);

        return 0;
    }

    // Construct GetOpt object by passing argc and argv arguments
    GetOpt::GetOpt_pp args(argc, argv);

    // Exceptions set to invalid format
    args.exceptions(std::ios::failbit);

    // Process arguments
    int help = args >> GetOpt::OptionPresent('h', "help");
    int arglength = args >> GetOpt::OptionPresent('l', "length");

    if (arglength) {
        try {
            args >> GetOpt::Option('l', "length", length);
        }
        catch (GetOpt::GetOptEx) {
            std::cerr << "nopassdb: value given to option -l --length wasn't a number." << std::endl;

            return 0;
        }
    }

    if (args.options_remain()) {
        std::cerr << "nopassdb: '" << args.options_remain() << "' is not a nopassdb command. See 'nopassdb --help'." << std::endl;

        return 0;
    }

    // Go through options
    std::vector<std::string> argvector(argv, argv+argc);

    for (std::string arg : argvector) {
        if (help && (arg == "-h" || arg == "--help")) {
            NoPassDB::ArgHelp();

            return 0;
        }

        if (arglength  && (arg == "-l" || arg == "--length")) {
            std::string password = NoPassDB::GetPassword("Password: ");
            NoPassDB::StartHashing(password, length, salt);

            return 0;
        }
    }

    std::string password = NoPassDB::GetPassword("Password: ");
    NoPassDB::StartHashing(password, length, salt);
    return 0;
}
