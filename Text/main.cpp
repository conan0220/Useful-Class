#include "Text.h"

int main()
{
	Text text;
	auto numbers = text.getData(text.loadFile("text.txt"));
	for (auto num : numbers)
		std::cout << num << " ";
}