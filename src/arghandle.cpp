#include "arghandle.h"

int argHandle(int argc, char ** argv)
{
    // Loop through all cast arguments
    for (int i = 0; i < argc; i++) {
        std::string arg = argv[i];
        std::size_t found = arg.find("nopassdb");

        // Skip first argument (program run location)
        if (found == std::string::npos) {
            if (arg == "--help" || arg == "-h") {
                std::cout << "help section" << std::endl;
                return 0;
            }

            else if (arg == "--length" || arg == "-l") {
                // Check if there is an arument after 'length'
                if (i + 2 > argc) {
                    std::cout << "Not enough arguments provided to " << arg << "." << std::endl;
                    return 0;
                } else {
                    std::stringstream buffer(argv[i + 1]);
                    int x;

                    // Check if argument is an integer
                    if(!(buffer >> x)) {
                        std::cout << "Given argument wasn't a number" << std::endl;
                        return 0;
                    } else {
                        if(std::to_string(x) != argv[i + 1]) {
                            std::cout << "Given argument wasn't a number" << std::endl;
                            return 0;
                        }
                    }

                    length = x;
                    return 1;
                }
            } else {
                std::cout << "nopassdb: '" << arg << "' is not a nopassdb command. See 'nopassdb --help'." << std::endl;
                return 0;
            }
        }
    }

    return 1;
}
