//https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>

int main()
{
	int n;
	std::string result_word;
	std::cin >> n;
	std::string* words = new std::string[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> words[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (words[i].size() > 10)
		{
			result_word = words[i].front() + std::to_string(words[i].size() - 2) + words[i].back();
			words[i] = result_word;
		}
		std::cout << words[i] << "\n";
	}

	delete[] words;
	return 0;
}