#include <iostream>

int main()
{
	int n;
	int x, y, z;
	int rx = 0;
	int ry = 0;
	int rz = 0;
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> x >> y >> z;
		rx += x;
		ry += y;
		rz += z;
	}
	if (rx == 0 && ry == 0 && rz == 0)
		std::cout << "YES";
	else
		std::cout << "NO";
	return 0;
}