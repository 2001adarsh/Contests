#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//Detecting a Cycle in undirected graph using DSU.

struct dsu
{
	vector<int> parent;

	void init(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int superParent(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = superParent(parent[x]);
	}

	void unite(int x, int y) {
		x = superParent(x);
		y = superParent(y);
		if (x != y) {
			parent[x] = y;
		}
	}
};

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	dsu G;
	G.init(n);
	bool cycle = false; //checks if cycle found

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (G.superParent(x) == G.superParent(y)) {
			cycle = true;
		} else {
			G.unite(x, y);
		}
	}

	if (cycle)
		cout << "There's a cycle in graph";
	else cout << "There's no cycle in graph";
	return 0;
}