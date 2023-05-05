#include "commands.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "history.h"

using namespace std;

void tokenize(char delimiter, string& s, vector<string>& inputs);
string get_stem(string path);

int main() {
    history history;
    const char delimiter = ' ';

    for (string line; getline(cin, line);) {
        vector<string> inputs;
        history.add_to_history(line);
        tokenize(delimiter, line, inputs);
        if (inputs.size() > 2 || inputs.empty()) {
            cout << "Invalid number of arguments provided." << endl;
            continue;
        }
        string command = inputs.at(0);
        if (!is_valid_command(command)) {
            cout
                    << "This is not a valid command. Use the help command for information about which are the possible commands."
                    << endl;
            continue;
        }

        if (command == "help") help();
        else if (command == "history") history.print_history();
        else if (command == "pwd") cout << string{filesystem::current_path()} << endl;
        else if (command == "ls") {
            for (const auto &resource: filesystem::directory_iterator(filesystem::current_path())) {
                cout << get_stem(resource.path()) << endl;
            }
        } else if (command == "mkdir") {
            bool is_created = filesystem::create_directories(string{filesystem::current_path()} + "/" + inputs.at(1));
            if (!is_created) cout << "There was an error in creating the new directory" << endl;
        } else if (command == "cd") {
            if (filesystem::is_directory(string{filesystem::current_path()} + "/" + inputs.at(1))) {
                filesystem::current_path(string{filesystem::current_path()} + "/" + inputs.at(1));
            } else {
                cout << "The argument specified is not a valid directory." << endl;
            }
        } else if (command == "touch") {
            if (filesystem::is_regular_file(string{filesystem::current_path()} + "/" + inputs.at(1))) {
                cout << "Provide another file name, as file with name " + inputs.at(1) + " already exists." << endl;
            } else {
                ofstream o{inputs.at(1)};
                o.close();
            }
        }
    }
}

void tokenize(char delimiter, string& s, vector<string>& inputs) {
    string word;
    for (auto x : s) {
        if (x == delimiter) {
            inputs.push_back(word);
            word = "";
        } else {
            word += x;
        }
    }
    if (!word.empty()) {
        inputs.push_back(word);
    }
}

string get_stem(string path) {
    string stem;
    for (const auto c: path) {
        if (c == '/') {
            stem = "";
        } else {
            stem += c;
        }
    }
    return stem;
}