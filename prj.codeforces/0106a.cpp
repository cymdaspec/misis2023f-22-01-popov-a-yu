//https://codeforces.com/problemset/problem/106/A

#include <iostream>
#include <map>

int main()
{
	char mk, m1, m2, d1, d2;
	std::cin >> mk >> d1 >> m1 >> d2 >> m2;

	int dn1 = 0;
	int dn2 = 0;

	std::map<char, unsigned> cards;
	cards['T'] = 10;
	cards['J'] = 11;
	cards['Q'] = 12;
	cards['K'] = 13;
	cards['A'] = 14;

	if (cards.count(d1) != 0)
		dn1 = cards[d1];
	else
		dn1 = d1 - '0'; //getting the number using indexes from ASCII

	if (cards.count(d2) != 0)
		dn2 = cards[d2];
	else
		dn2 = d2 - '0'; //getting the number using indexes from ASCII

	if ((m1 == m2 && dn1 > dn2) || (m1 == mk && m2 != mk))
		std::cout << "YES";
	else
		std::cout << "NO";
	
	return 0;
}