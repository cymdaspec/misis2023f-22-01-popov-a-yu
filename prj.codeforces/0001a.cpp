#include <cmath>
#include <iostream>

int main()
{
    double n, m, a;
    long long c;
    std::cin >> n >> m >> a;
    c = std::ceil(n / a) * std::ceil(m / a);
    std::cout << c;
    return 0;
}