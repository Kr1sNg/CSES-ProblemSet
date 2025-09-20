#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int>	bfs(int start, std::vector<std::vector<int>> const &adj, int n)
{
	std::vector<int>	dist(n + 1, -1);
	std::queue<int>		q;

	q.push(start);
	dist[start] = 0;

	int	farthesNode = start;
	while (!q.empty())
	{
		int	u = q.front();
		q.pop();
		for (size_t i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if (dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
				if (dist[v] > dist[farthesNode])
					farthesNode = v;
			}
		}
	}
	return (std::make_pair(farthesNode, dist[farthesNode]));
}

int	main(void)
{
	int	n;
	std::cin >> n;
	std::vector<std::vector<int>> adj(n + 1);

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	std::pair<int, int> p1 = bfs(1, adj, n);
	std::pair<int, int> p2 = bfs(p1.first, adj, n);
	std::cout << p2.second << std::endl;
	return (0);
}