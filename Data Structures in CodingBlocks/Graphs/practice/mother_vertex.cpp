#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

//Finding at least one Mother vertex, which can traverse all the other nodes.

class Graph
{
	int V;
	list<int> *l;
public:
	vector<int> order;
	Graph(int V) {
		this-> V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void dfs(int node, bool* vis) {
		vis[node] = true;
		for (auto nbr : l[node]) {
			if (!vis[nbr]) dfs(nbr, vis);
		}
		order.push_back(node);
	}

	void dfs_util(int n) {
		bool vis[n + 1] = {false};
		for (int i = 0; i < n; i++)
			if (!vis[i])
				dfs(i, vis);
	}

	void findMother(int node , bool* vis) {
		vis[node] = true;
		for (auto nbr : l[node])
			if (!vis[nbr]) findMother(nbr, vis);
	}
};

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	g.dfs_util(7);
	int last = g.order[6];
	bool vis[7] = {false};

	g.findMother(last, vis);

	bool ans = true;
	for (int i = 0; i < 7; i++)
		if (!vis[i])
			ans = false;
	if (ans)
		cout << "One of the mother vertex found at index: " << last;
	else
		cout << "Mother index not found";

	return 0;
}