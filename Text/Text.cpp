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
	return 48 <= static_cast<int>(ch) && static_cast<int>(ch) <= 57;
}

/*
* Description: return doubles in string
* Parameters: str(string)
* str -> just string
*/
// std::vector<double> Text::getDoubleInString(std::string str)
// {
// 	std::vector<double> ans;
// 	std::string temp = "";
// 	char ch;
// 	for (int i = 0; i < str.size(); i++)
// 	{
// 		ch = str[i];
// 		// 現在的字元是 '-', 下一個字元是數字, 現在的字元是最後第二個, 數字暫存區是空的
// 		if (ch == '-' && isNumber(str[i + 1]) && i < str.size() - 1 && temp.empty())
// 		{
// 			temp += ch;
// 		}
// 		else if (isNumber(ch) || ch == '.')
// 		{
// 			temp += ch;
// 		}
// 		else if (!temp.empty())
// 		{
// 			ans.push_back(std::stof(temp));
// 			temp.clear();
// 		}
// 	}
// 	if (!temp.empty())
// 	{
// 		ans.push_back(std::stof(temp));
// 		temp.clear();
// 	}
// 	return ans;
// }

std::vector<double> Text::getDoubleInString(std::string str)
{
	std::vector<double> ans;
	std::string temp = "";
	int i = -1;
	while (++i < str.size())
	{
		// if the first char is '-', add '-' to temp and identify from str[1], otherwise identify from str[0]
		if (str[i] == '-') {
			temp += '-';
			i++;
		}
		// 小數點前的判斷
		while (true)
		{
			// 遇到數字就加到 temp
			if (isNumber(str[i]))
				temp += str[i];
			// 遇到小數點 跳出迴圈 進到下一個迴圈判斷小數點後的位數
			else if (str[i] == '.') {
				temp += str[i];
				break;
			}
			// 遇到除了 數字 或 小數點
			else {
				if (!temp.empty()) {
					//std::cerr << std::endl << temp;
					ans.push_back(std::stof(temp));
					
					temp.clear();
					break;
				}
				else 
					break;
			}
			i++;
		}
		if (temp.empty())
			continue;
		while (true)
		{
			i++;
			if (isNumber(str[i]))
				temp += str[i];
			else {
				if (temp == ".") {
					temp.clear();
					break;
				}
				//std::cerr << std::endl << temp;
				ans.push_back(std::stof(temp));
				temp.clear();
				break;
			}
		}
	}
	return ans;
}