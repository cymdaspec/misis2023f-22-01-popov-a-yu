//https://codeforces.com/problemset/problem/546/A

#include <iostream>

int main()
{
	int k;
	long long n;
	int w;
	int sum = 0;
	std::cin >> k >> n >> w;
	for (int i = 0; i < w; i++)
	{
		sum += (i + 1) * k;
	}
	sum < n ?
		std::cout << 0
	:
		std::cout << sum - n;

	
	return 0;
}