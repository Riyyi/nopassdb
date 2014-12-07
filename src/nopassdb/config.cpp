#include "config.h"

std::string GetName() {
#ifdef _WIN32
    return "config.txt";
#elif defined(__unix) || defined (__APPLE__)
    return "nopassdb.conf";
#endif
}

std::string GetLocation() {
    char* systemenv;
    std::string location;

#ifdef _WIN32
    systemenv = getenv("APPDATA");
    location.assign(systemenv);
    location += "\\nopassdb";
#elif defined(__unix) || defined (__APPLE__)
    systemenv = getenv("HOME");
    location.assign(systemenv);
    location += "/.config/nopassdb/";
#endif

    return location;
}

int NoPassDB::CheckConfig(int & length, std::string & salt) {
    std::string line;
    std::ifstream config;

    // Check for config in same location
    config.open(GetName());
    if (config.is_open()) {
        // Get length from config
        getline(config, line);
        length = atoi(line.c_str());;
        if (length == 0) {
            length = 20;
        }

        // Get salt from config
        getline(config, line);
        salt = line;
        if (line != "") {
            config.close();
            return 1;
        }

        config.close();
        return 0;
    }

    // Check for config in system env
    config.open(GetLocation() + GetName());
    if (config.is_open()) {
        // Get length from config
        getline(config, line);
        length = atoi(line.c_str());;
        if (length == 0) {
            length = 20;
        }

        // Get salt from config
        getline(config, line);
        salt = line;
        if (line != "") {
            config.close();
            return 1;
        }

        config.close();
        return 0;
    }

    return 0;
}

int NoPassDB::CreateConfig(std::string salt) {
    std::string location = GetLocation();
    std::string mkdir;

#ifdef _WIN32
    mkdir = "cmd /c mkdir " + location;
#elif defined(__unix) || defined (__APPLE__)
    mkdir = "mkdir " + location;
#endif
    system(mkdir.c_str());

    std::ofstream config(location + GetName());
    if (config.is_open()) {
        config << "20\n";
        config << salt + "\n";

        config.close();
    }

    return 0;
}
