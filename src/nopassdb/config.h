#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

namespace NoPassDB {
    int CheckConfig(int & length, std::string & salt);
    int CreateConfig(std::string salt);
}

#endif // CONFIG_H
