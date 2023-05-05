//
// Created by aarav jain on 2023-05-04.
//

#ifndef LINUX_SHELL_HISTORY_H
#define LINUX_SHELL_HISTORY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class history {
private:
    vector<string> history;

public:
    void add_to_history(const string& command) { history.push_back(command); };
    void print_history() {
        for (string& command: history) {
            cout << command << endl;
        }
    }
};


#endif //LINUX_SHELL_HISTORY_H
