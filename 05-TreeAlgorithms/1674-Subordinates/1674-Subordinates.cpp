#include <vector>
#include <iostream>

class Node
{
	public:
		int	_id;
		std::vector<Node *>	_tree;
		int	_subordinates;

		Node(int id): _id(id), _subordinates(0) {};
		~Node()	{};
};

int	DepthFirstSearch(Node *node)
{
	int count = 0;

	for (size_t i = 0; i < node->_tree.size(); ++i)
	{
		Node *child = node->_tree[i];
		count += 1 + DepthFirstSearch(child);
	}
	node->_subordinates = count;
	return (count);
}

int	main(void)
{
	int	n;
	std::cin >> n;

	std::vector<Node *>	array;
	array.reserve(n);
	for (int i = 0; i < n; ++i)
		array.push_back(new Node(i + 1));

	for (int i = 2; i <= n; ++i)
	{
		int	boss;
		std::cin >> boss;
		array[boss - 1]->_tree.push_back(array[i - 1]);
	}

	DepthFirstSearch(array[0]);

	for (int i = 0; i < n; ++i)
	{
		std::cout << array[i]->_subordinates << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < array.size(); ++i)
		delete array[i];

	return (0);
}


/* Solution
#include <iostream>
#include <vector>
using namespace std;

const int N = 200001;
vector<int> g[N];
int subordinates[N];

void dfs(int node) {
    for (int child : g[node]) {
        dfs(child);
        subordinates[node] += subordinates[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << ' ';
    }
    cout << '\n';
}
*/