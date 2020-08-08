#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class DSU
{
	int V;
	std::vector<int> parent;
	//std::vector<int> rank;
public:
	DSU(int V) {
		this->V = V;
		parent.resize(V + 1);
		//rank.resize(V);
		for (int i = 1; i <= V; i++) {
			parent[i] = i;
			//	rank[i] = 0;
		}
	}

	//Super Parent
	int Find(int x) { //Returns the single representative
		if (x == parent[x])
			return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		//If both have same super parent then they are already in same set.
		if (x != y) {
			parent[x] = y;
			//merging the set based on rank
			/*if (rank[x] < rank[y]) {
				parent[x] = y;
			}
			else if (rank[x] > rank[y]) {
				parent[y] = x;
			} else { //order doesn't matter
				parent[x] = y;
				rank[y]++;
			}*/
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
	DSU G(n );
	for (int i = 0; i < m; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t) {
			if (G.Find(x) != G.Find(y)) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		} else {
			G.Union(x, y);
		}
	}

	return 0;
}