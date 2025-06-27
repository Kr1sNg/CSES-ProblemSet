/*

*/

#include <iostream>

int	main(void)
{
	size_t n;
	std::cin >> n;

	std::cout << n << " ";
	while (n > 0 && n != 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
			std::cout << n << " ";
		}
		else
		{
			n = n * 3 + 1;
			std::cout << n << " ";
		}
	}
	std::cout << std::endl;
	
	return (0);
}
