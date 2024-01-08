#include <iostream>
#include <cmath>

int main()
{
    int t;
    double n;
    long long c;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        c = 0;
        std::cin >> n;
        c = ceil((n / 2) - 1);
        std::cout << c << std::endl;
    }

    return 0;
}