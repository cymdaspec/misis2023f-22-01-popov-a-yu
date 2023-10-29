//https://codeforces.com/problemset/problem/282/A

#include <iostream>
#include <string>

int main()
{
	int n;
	int res = 0;
	std::cin >> n;
	std::string *input = new std::string[n];
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (input[i][0] == '+' || input[i][1] == '+' || input[i][2] == '+')
			res++;
		else
			res--;
	}

	std::cout << res << "\n";

	delete[] input;
	return 0;
}