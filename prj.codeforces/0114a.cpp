//https://codeforces.com/problemset/problem/114/A

#include <iostream>

int main()
{
	int k, l;
	std::cin >> k >> l;
	int c = 0;

	if (l % k == 0)
	{
		while (l > k && l%k == 0)
		{
			l /= k;
			c++;
		}
		if (l == k) {
			std::cout << "YES \n" << c;
		}
		else
			std::cout << "NO";
	}
	else
		std::cout << "NO";

	return 0;
}