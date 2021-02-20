/* ISO C++ forbids conversion from string literal to char* 
   (can`t use strcat) */

#include "config.h"
#include "../loader/loader.h"
#include "../lexer/lexer.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

Config *config;

Config::Config(int argc, char **argv) {
    if(argc < 2)
        throw runtime_error("Too low arguments");
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-' && argv[i][1] == '-') // argv[i] is flag (--)
            parameters[argv[i]] = 1;
        else if(argv[i][0] == '-') { // argv[i] is parameter (-)
            if(i + 1 >= argc)
                throw runtime_error(string("Expected parameter value: ") + argv[i]);

            int num = 0;
            bool is_number = true;
            try {
                num = stoi(argv[i + 1]);
            }
            catch(invalid_argument) {
                throw runtime_error(string("String-to-int coversion error: ") + argv[i + 1]); 
            }
            parameters[argv[i]] = num;
            i++; 
        }
        else // argv[i] is input file (no prefix)
            inputs.push_back(argv[i]);
    }
}

void Config::run() {
    if(parameters["--help"])
        show_help();
    else {
        if(inputs.size() > 1)
            throw runtime_error("Multiply input not supported yet");
        if(parameters["--verbose"])
            clog << "starting lexer..." << endl;
        auto lexems = Lexer(Loader::load_file(inputs[0].c_str())).get_tokens();
        for(int i = 0; i < lexems.size(); i++)
            cout << lexems[i].word << endl;
    }
}

void Config::show_help() {
    try {
        cout << Loader::load_file("Helpfile") << endl;
    }
    catch(runtime_error) {
        throw runtime_error("Helpfile is missing");
    }
}