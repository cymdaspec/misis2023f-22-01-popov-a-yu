#include <iostream>

int main()
{
    int x;
    int c = 0;
    std::cin >> x;
    while (x > 0)
    {
        x -= 5;
        c += 1;
    }
    std::cout << c;
    return 0;
}