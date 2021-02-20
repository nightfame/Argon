#include <iostream>
#include <stdexcept>
#include "config/config.h"
#include "loader/loader.h"
#include "lexer/lexer.h"

using namespace std;

int main(int argc, char **argv) {
    try {
        config = new Config(argc, argv);
        config->run();
    }
    catch(runtime_error e) {
        cerr << e.what() << endl;
        exit(-1);
    }

    // Finalization
    delete config;
}