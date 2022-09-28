#include "Timer.h"

int main()
{
    {
        Timer timer;
        int a = 0;
        for (int i = 0; i < 1000; i++)
        {
            a += 1;
        }
    }
    std::cin.get();
}