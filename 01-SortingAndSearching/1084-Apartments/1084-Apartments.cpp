#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int	n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int>	desired_sz;
	std::vector<int>	apt_sz;

	for (int i = 0; i < n; ++i)
	{
		int sz;
		std::cin >> sz;
		desired_sz.push_back(sz);
	}
	std::sort(desired_sz.begin(), desired_sz.end());

	for (int i = 0; i < m; ++i)
	{
		int sz;
		std::cin >> sz;
		apt_sz.push_back(sz);
	}
	std::sort(apt_sz.begin(), apt_sz.end());

	int	count = 0;
	int i = 0;
	int j = 0;
	while(i < n && j < m)
	{
		if (desired_sz[i] >= apt_sz[j] - k && desired_sz[i] <= apt_sz[j] + k)
		{
			count++;
			i++;
			j++;
		}
		else if (desired_sz[i] > apt_sz[j] + k)
			j++;
		else
			i++;
	}
	std::cout << count << std::endl;
	return (0);
}