//
// Created by aarav jain on 2023-05-02.
//

#ifndef LINUX_SHELL_COMMANDS_H
#define LINUX_SHELL_COMMANDS_H

#include <string>
#include <vector>
#include <map>

using namespace std;

void help();

bool is_valid_command(string command);

const map<string, string> commands = {
        {"cd",  "Changes current working directory"},
        {"help", "Lists all available commands."},
        {"mkdir", "Makes a new directory in current working directory."},
        {"history", "Prints the history of commands fed as input in this shell session."},
        {"pwd", "Prints the current working directory."},
        {"ls", "Lists all of the files and folders in current working directory."},
        {"touch", "Creates a new file in the current working directory."}};

#endif //LINUX_SHELL_COMMANDS_H
