#ifndef LOADER_H
#define LOADER_H

#include <string>

using namespace std;  

class Loader {
public:
    static string load_file(const char* filename);
};

#endif 