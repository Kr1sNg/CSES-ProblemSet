#include <iostream>
#include <set>

int	main(void)
{
	std::set<int>	list;

	int	n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int	x;
		std::cin >> x;
		list.insert(x);
	}

	std::cout << list.size() << std::endl;
	return (0);
}
