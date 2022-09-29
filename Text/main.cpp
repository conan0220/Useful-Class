#include "Text.h"

int main()
{
	auto txt = loadFile("text.txt");
	auto numbers = getData(txt);
	for (auto num : numbers)
		std::cout << num << " ";
}