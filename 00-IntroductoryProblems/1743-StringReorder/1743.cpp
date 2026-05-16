#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main(void)
{
  std::string input;
  std::cin >> input;

  int freq[26] = {0};
  int len = input.length();

  for (int i = 0; i < len; i++)
    freq[input[i] - 'A']++;

  std::priority_queue<std::pair<int, char> > pq;
  for (int i = 0; i < 26; i++)
    if (freq[i] > 0)
      pq.push(std::make_pair(freq[i], char('A' + i)));

  std::string result = "";

  while (pq.size() > 1)
  {
    std::pair<int, char> p1 = pq.top();
    pq.pop();
    std::pair<int, char> p2 = pq.top();
    pq.pop();

    result += p1.second;
    result += p2.second;

    p1.first--;
    p2.first--;

    if (p1.first > 0)
      pq.push(p1);
    if (p2.first > 0)
      pq.push(p2);
  }

  if (!pq.empty())
  {
    std::pair<int, char> last = pq.top();
    if (last.first > 1)
    {
      std::cout << -1 << std::endl;
      return 0;
    }
    result += last.second;
  }

  std::cout << result << std::endl;
  return 0;
}