#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//Kruskal's algorithm for Minimum Spanning Tree
// Step 1 => Sort the edges according to their weights.
// Step 2 => Add the worthy edge(edge which do not form a circle)

class dsu
{
public:
	vector<int> parent;
	dsu(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
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
	//tuple type
	vector<vector<int> > edges(m);

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		edges[i] = {w, x, y}; //adding the whole as a vector
	}
	//step 1
	sort(edges.begin(), edges.end());
	dsu G(n);
	int totalweight = 0;

	for (int i = 0; i < m; i++) {
		int x = edges[i][1];
		int y = edges[i][2];
		int w = edges[i][0];

		if (G.find(x) != G.find(y)) { //they donot form an edge
			G.unite(x, y);
			totalweight += w;
		}
	}

	cout << totalweight;

	return 0;
}