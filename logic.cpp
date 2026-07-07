#include "logic.h"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void input(std::string& task) {
    std::cout << "\nEnter task: ";
    std::getline(std::cin, task);
}

void help() {
    std::cout << "\n--------Help---------\n";
    std::cout << "Add with index: +<index> <task>\n";
    std::cout << "Add without index: + <task>\n";
    std::cout << "Remove: -<index>\n";
    std::cout << "Change order: <start_index> > <end_index>\n";
    std::cout << "Check list: list\n";
    std::cout << "Exit program: exit\n";
    std::cout << "---------------------\n";
}

void addTask(std::vector<std::string>& tasks, const std::string& command) {
    if (command.size() > 2 && command[1] == ' ') {
        tasks.push_back(command.substr(2));
        return;
    }

    if (command.size() > 2 && std::isdigit(static_cast<unsigned char>(command[1]))) {
        int index = command[1] - '0';
        std::string taskName = command.substr(3);
        if (tasks.size() == 10) {
            std::cout << "Max is 10\n";
        } else if (index >= 0 && index <= static_cast<int>(tasks.size())) {
            tasks.insert(tasks.begin() + index, taskName);
        } else {
            std::cout << "Invalid index\n";
        }
    }
}

void removeTask(std::vector<std::string>& tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index);
    } else {
        std::cout << "Invalid index\n";
    }
}

void printArray(const std::vector<std::string>& tasks) {
    std::cout << "\n--------List---------\n";
    for (int i = 0; i < static_cast<int>(tasks.size()); i++) {
        std::cout << i << ". " << tasks[i] << std::endl;
    }
    std::cout << "---------------------\n";
}

void changeOrder(std::vector<std::string>& tasks, int start, int end) {
    if (start >= 0 && start < static_cast<int>(tasks.size()) &&
        end >= 0 && end < static_cast<int>(tasks.size())) {
        std::string temp = tasks[start];
        tasks.erase(tasks.begin() + start);
        tasks.insert(tasks.begin() + end, temp);
    } else {
        std::cout << "Invalid index\n";
    }
}

bool exitProgram(const std::string& command) {
    return command == "exit" || command == "Exit";
}

void task() {
    std::vector<std::string> tasks;
    std::string command;

    while (true) {
        input(command);

        if (command == "help" || command == "Help") {
            help();
        } else if (command[0] == '+') {
            addTask(tasks, command);
        } else if (command[0] == '-') {
            removeTask(tasks, command[1] - '0');
        } else if (command == "list" || command == "List") {
            printArray(tasks);
        } else if (command.size() > 4 && command[2] == '>' && command[3] == ' ') {
            int start = command[0] - '0';
            int end = command[4] - '0';
            changeOrder(tasks, start, end);
        } else if (exitProgram(command)) {
            break;
        } else {
            std::cout << "Unrecognized command, try \"help\"\n";
        }
    }
}

int main() {
    task();
    return 0;
}
