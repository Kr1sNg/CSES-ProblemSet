// #include <iostream>

// int	main()
// {
// 	int	n;
// 	std::cin >> n;
// 	int line[n - 1];
// 	unsigned long long	sum = 0;
// 	for (int i = 0; i < n - 1; i++)
// 	{
// 		std::cin >> line[i];
// 		sum += line[i];
// 	}
// 	unsigned long long total = 1LL * (1 + n) * n / 2;
// 	std::cout << total - sum << std::endl;
// 	return (0);
// }

// /* Better Solution

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << "\n";
}

// */