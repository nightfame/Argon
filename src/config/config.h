#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Config {
public:
    map<string, int> parameters;
    vector<string> inputs;

    Config(int argc, char **argv);

    void run();

    static void show_help();
};

extern Config *config;

#endif