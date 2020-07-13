#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

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
	}

	void dfs_helper(int node, int y, vector<bool> vis, int& ans) {
		vis[node] = true;
		//base case
		if (node == y) {
			ans++;
			return;
		}
		//recursive case
		for (auto nbr : l[node]) {
			if (!vis[nbr]) {
				dfs_helper(nbr, y, vis, ans) ;
			}
		}
		return ;
	}

	void dfs(int x, int y) {
		vector<bool> visited(V + 1, false);
		int ans = 0;
		dfs_helper(x, y, visited, ans);
		cout << ans;
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
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 3);
	g.addEdge(2, 5);
	g.addEdge(2, 4);

	int s = 1, d = 3;
	g.dfs(s, d);

	return 0;
}