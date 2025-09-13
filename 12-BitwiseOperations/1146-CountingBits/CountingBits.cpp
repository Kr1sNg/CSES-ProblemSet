#include <iostream>

int main(void)
{
	unsigned long long	n;
	std::cin >> n;

	unsigned long long	total = 0;
	unsigned long long	k = 0;
	while ((1ULL << k) <= n) // make sure that 1 is using unsigned long long
	{
		unsigned long long period = 1ULL << (k + 1);
		unsigned long long ones_per_period = 1ULL << k;
		unsigned long long complete_periods = n / period;
		total += complete_periods * ones_per_period;
		unsigned long long remainder = n % period;
		if ((remainder) >= (1ULL << k))
			total += remainder - (1ULL << k) + 1;
		++k;
	}

	std::cout << total << std::endl;
	return (0);
}
