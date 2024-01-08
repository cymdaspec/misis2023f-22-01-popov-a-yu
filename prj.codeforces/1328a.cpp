#include <iostream>

int main() {

	int t, x, y, w;
	std::cin >> t;

	while (t>0) 
	{

		std::cin >> x >> y;

		if (x % y == 0)
		{
			std::cout << 0 << std::endl;
		}
		else 
		{

			w = x % y;

			std::cout << y - w << std::endl;

		}
		t--;
	}


	return 0;
}