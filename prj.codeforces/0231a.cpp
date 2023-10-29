//https://codeforces.com/problemset/problem/231/A

#include <iostream>

int main()
{
	int n;
	int count = 0;
	std::cin >> n;
	int **input = new int*[n];

	for (int i = 0; i < n; i++)
	{
		input[i] = new int[3];
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i][0];
		std::cin >> input[i][1];
		std::cin >> input[i][2];
		count += ((input[i][0] + input[i][1] + input[i][2])/2);
	}

	std::cout << count << "\n";

	delete[] input;
	return 0;
}