//https://codeforces.com/problemset/problem/677/A

#include <iostream>

int main()
{
	int n;
	int h;
	int width = 0;
	std::cin >> n >> h;
	int* input = new int [n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
		width += (1 + (input[i] > h));
		
	}
	
	std::cout << width;

	delete[] input;
	return 0;
}