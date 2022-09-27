#include "Text.h"
#include <string>

/*
* Description: load file and return text(vector<string>)
* Parameters: filePath(string)
*/
std::vector<std::string> Text::loadFile(std::string filePath)
{
	std::ifstream file(filePath);
	std::string lineText = "";
	std::vector<std::string> txt;
	while (std::getline(file, lineText))
	{
		txt.push_back(lineText);
	}
	file.close();
	return txt;
}

/*
* Description: get data in text and return data(vector<double>)
* Parameters: text(string), start(int)
* 	text -> use loadFile() to get text
* 	start -> where start to get data depending on line number
*/
std::vector<double> Text::getData(std::vector<std::string> text, int start)
{
	std::vector<double> ans;
	std::vector<double> temp;
	for (int i = start; i < text.size(); i++)
	{
		temp = getDoubleInString(text[i]);
		ans.insert(ans.end(), temp.begin(), temp.end());
	}
	return ans;
}

/*
* Description: identify whether char is number
* Parameters: ch(char)
* ch -> any char
*/
bool Text::isNumber(char ch)
{
	return 48 <= static_cast<int>(ch) && static_cast<int>(ch) <= 57 ? true : false;
}

/*
* Description: return doubles in string
* Parameters: str(string)
* str -> just string
*/
std::vector<double> Text::getDoubleInString(std::string str)
{
	std::vector<double> ans;
	std::string temp = "";
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (ch == '-' && isNumber(str[i + 1]) && i < str.size() - 1 && temp.empty())
		{
			temp += ch;
		}
		else if (isNumber(ch) || ch == '.')
		{
			temp += ch;
		}
		else if (!temp.empty())
		{
			ans.push_back(std::stof(temp));
			temp.clear();
		}
	}
	if (!temp.empty())
	{
		ans.push_back(std::stof(temp));
		temp.clear();
	}
	return ans;
}