/* ISO C++ forbids conversion from string literal to char* 
   (can`t use strcat) */

#include "loader.h"
#include <fstream>
#include <stdexcept>
 
using namespace std;

string Loader::load_file(const char* filename) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE] = {0};
    ifstream file (filename);
    if(!file)
        throw runtime_error(string("Invalid filename: ") + filename);
    
    file.read(buffer, BUFFER_SIZE);
    return string(buffer); 
}