#include "Text.h"

int main()
{
	std::vector<std::string> txt = loadFile("../input/text.txt");
	for (const std::string &str : txt)
	{
		if (inString(str, "arc"))
		{
			for (double num : getDoubleFromString(str))
				std::cout << num << " ";
			std::cout << std::endl;
		}
	}
	std::cin.get();
}