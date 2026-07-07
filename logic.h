#ifndef LOGIC_H
#define LOGIC_H

#include <string>
#include <vector>

void input(std::string& task);
void help();
void addTask(std::vector<std::string>& tasks, const std::string& command);
void removeTask(std::vector<std::string>& tasks, int index);
void printArray(const std::vector<std::string>& tasks);
void changeOrder(std::vector<std::string>& tasks, int start, int end);
bool exitProgram(const std::string& command);
void task();

#endif
