#include <iostream>
#include <vector>

bool	is_prime(size_t n)
{
	if (n < 2)
		return (false);
	if (n % 2 == 0)
		return (n == 2);
	for (size_t i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return (false);
	}
	return (true);
}

size_t	next_prime(size_t n)
{
	if (n < 2)
		return (2);
	size_t next = n + 1;
	while (!is_prime(next))
		next++;
	return (next);
}

int	main(void)
{
	int t;
	std::cin >> t;
	std::vector<size_t>	nu;

	for (int i = 0; i < t; ++i)
	{
		size_t	n;
		std::cin >> n;
		nu.push_back(n);
	}

	for (int i = 0; i < t; ++i)
		std::cout << next_prime(nu[i]) << std::endl;
	return (0);
}