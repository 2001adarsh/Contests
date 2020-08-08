#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class dsu
{
	int V;
	vector<int> parent;
public:
	dsu(int V) {
		this->V = V;
		parent.resize(V);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) { //dsu find
		return (x == parent[x] ? x : (parent[x] = find(parent[x])) );
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			parent[x] = max(parent[x] , parent[y]);
			parent[y] = max(parent[x], parent[y]);
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

	int n, q;
	cin >> n >> q;
	int l[q + 1], r[q + 1], c[q + 1];
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i] >> c[i];
	}

	dsu G(n + 2);
	int result[n + 1] = {0};

	for (int i = q - 1; i >= 0; i--) {
		int origin = G.find(l[i]);

		while (origin <= r[i]) {
			result[origin] = c[i];
			//uniting the index
			G.unite(origin, origin + 1);
			origin = G.find(origin);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}