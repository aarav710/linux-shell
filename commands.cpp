#include <iostream>
#include "commands.h"

using namespace std;


void help() {
    cout << "Commands available in this linux shell are:" << endl;
    auto it = commands.begin();
    while (it != commands.end()) {
        cout << it->first << " : " << it->second << endl;
        ++it;
    }
}

bool is_valid_command(string command) {
    if (commands.find(command) == commands.end()) {
        return false;
    }
    return true;
}