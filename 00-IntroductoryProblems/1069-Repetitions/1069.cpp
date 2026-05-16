#include <iostream>
#include <string>

int main(void)
{
	std::string input;
	std::cin >> input;

	size_t	max = 1;
	size_t	count = 1;
	for (size_t i = 0; input[i] != '\0' && input[i + 1] != '\0'; ++i)
	{
		if (input[i + 1] == input[i])
		{
			count++;
			max = (count > max) ? count : max;
		}
		else
			count = 1;
	}
	std::cout << max << std::endl;
}