#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//BFS program to print no. of node at each level

class Graph
{
	int V;
	list<int> *l;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs(int node, int k) {
		std::vector<int> level(V, 0);
		std::vector<int> vis(V, false);
		queue<int> q;
		q.push(node);

		vis[node] = true;
		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (!vis[nbr]) {
					level[nbr] = level[node] + 1;
					vis[nbr] = true;
					q.push(nbr);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < V; i++)
			if (level[i] == k)
				cnt++;
		cout << cnt;
	}
};

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);

	g.bfs(0, 2);
	return 0;
}