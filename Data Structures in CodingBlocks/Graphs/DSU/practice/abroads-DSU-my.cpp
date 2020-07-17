#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class dsu
{
	int V;
	vector<int> parent;
public:
	vector<int> size;
	int mx;
	dsu(int V, vector<int>& pl) {
		this->V = V;
		parent.resize(V);
		iota(parent.begin(), parent.end(), 0);

		size.resize(V);
		for (int i = 0; i < V; i++) {
			size[i] = pl[i];
		}
		mx = 0;
	}

	int find(int x) {
		return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if ( x != y) {
			parent[x] = y;
			size[y] += size[x];
			size[x] = 0;
			mx = max(size[y], mx);
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
	//Inserted n,m,q;
	int n, m, q;
	cin >> n >> m >> q;

	// all values of n
	vector<int> pl(n, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> pl[i];
	}
	for (int i = 0; i < n; i++)
		cout << pl[i] << " ";

	//all edges inserted.
	int left[m] , right[m];
	vector<bool> edgeT(m + 1 , false);
	for (int i = 0; i < m; i++) {
		edgeT[i] = true;
		int x, y;
		cin >> x >> y;
		x--; y--;
		left[i] = x; right[i] = y;
	}
	for (int i = 0; i < m; i++) {
		cout << left[i] << " " << right[i] << endl;
	}

	char ch[q + 1];
	int x[q + 1], y[q + 1];
	for (int i = 0; i < q; i++) {
		cin >> ch[i];
		if (ch[i] == 'D') {
			cin >> x[i];
			x[i]--;
			y[i] = -1;
			edgeT[x[i]] = true;
		} else {
			cin >> x[i] >> y[i];
			x[i]--;
			pl[x[i]] = y[i];
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ch[i] << " " << x[i] << " " << y[i] << " " << edgeT[i] << endl;
	}

	dsu G(n, pl);

	for (int i = 0; i < m; i++) {
		if (!edgeT[i]) {
			G.unite(left[i], right[i]);
		}
	}
	for (int i = q - 1; i >= 0; i--) {
		if (ch[i] == 'D') {
			cout << G.mx << endl;
			G.unite(left[x[i]] , right[x[i]]);
		} else {
			int before = pl[x[i]];
			pl[x[i]] = y[i];
			int get = G.find(x[i]);
			int resultant = G.size[get] - before + y[i];
			G.size[get] = resultant;
			G.mx = max(G.mx, resultant);
			cout << G.mx << endl;
		}
	}

	return 0;
}