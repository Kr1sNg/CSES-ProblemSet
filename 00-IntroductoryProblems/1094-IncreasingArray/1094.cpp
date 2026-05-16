#include <iostream>
#include <vector>

int main(void)
{
  int n;
  std::cin >> n;
  
  std::vector<long> x(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }

  long  moves = 0;
  for (int i = 1; i < n; i++) {
    if (x[i] < x[i - 1]) {
      moves += (x[i - 1] - x[i]);
      x[i] = x[i - 1];
    }
  }

  std::cout << moves << std::endl;
  return 0;
}