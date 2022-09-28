#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Text 
{
public:
	Text() {}
	~Text() {}

	std::vector<std::string> loadFile(std::string filePath = "");
	std::vector<double> getData(std::vector<std::string> text, int start = 0);
	
private:
	bool isNumber(char ch);
	std::vector<double> getDoubleInString(std::string str);
};