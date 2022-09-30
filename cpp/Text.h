#pragma once

#include <iostream>
#include <fstream>
#include <vector>

bool isNumber(char ch);
bool inString(std::string str, std::string target);

std::vector<std::string> loadFile(std::string filePath = "");
std::vector<double> getDoubleInString(std::string str);
std::vector<double> getData(std::vector<std::string> text, int start = 0);