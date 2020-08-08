#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

struct DSU
{
	vector<int> parent, sz;
	int total_component;

	void init(int n) {
		parent.resize(n);	//contains superParent of any node.
		sz.resize(n);	//size of connected component if it is a superParent
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sz[i] = 1;
		}
		total_component = n;
	}

	int superParent(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = superParent(parent[x]); //path compression for future
	}

	void unite(int x, int y) { //union/joinning of two nodes x and y.
		x = superParent(x);
		y = superParent(y);
		if (x != y) { //if they are in diff component(having different superparent)
			parent[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			total_component--;
		}
	}
} G;

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, n, m;
	cin >> n >> m;
	G.init(n);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		G.unite(x, y);
	}
	//now all components are connected
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int superparentI = G.superParent(i);
		ans += (n - G.sz[superparentI]);
	}
	cout << ans / 2; //cause everything is being taken twice.
	return 0;
}