#include <iostream>

int main()
{
    int y, w, a;
    int b = 6;
    std::cin >> y >> w;

    y > w
        ? a = 7 - y
        : a = 7 - w;

    for (int i = 2; i <= 6; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            a /= i;
            b /= i;
        }
            
    }
    std::cout << a << "/" << b;

    return 0;
}