#include "Text.h"

int main()
{
	Text text;
	auto txt = text.loadFile("text.txt");
	auto numbers = text.getData(txt);
	for (auto num : numbers)
	{
		std::cout << num << " ";
	}
}