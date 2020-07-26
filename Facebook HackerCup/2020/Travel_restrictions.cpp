#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class Graph
{
	int V;

public:
	vector<int> *g;
	Graph(int V) {
		this->V = V;
		g = new vector<int>[V];
	}

	void addEdges(int x, int y) {
		g[x].push_back(y);
	}

	void dfs_run(int x, vector<bool>& vis, int i, vector<string>& st) {
		vis[x] = true;
		st[i][x] = 'Y';
		//cout << i << "->" << x << " :" << st[i][x] << endl;
		for (auto nbr : g[x]) {
			if (!vis[nbr])
				dfs_run(nbr, vis, i, st);
		}
	}

	void dfs(vector<string>& st) {

		vector<bool> vis(V, false);

		for (int i = 0; i < V; i++) {
			vis.clear();
			vis.resize(V);
			for (int i = 0; i < V; ++i)
			{
				vis[i] = false;
			}
			dfs_run(i, vis, i, st);
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

	int t, k = 0;
	cin >> t;
	while (t--) {
		k++;
		cout << "Case #" << k << ":" << endl;
		int n;
		cin >> n;
		char in[n], out[n];
		for (int i = 0; i < n; i++)
			cin >> in[i];
		for (int i = 0; i < n; i++)
			cin >> out[i];

		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			string s = "";
			for (int j = 0; j < n; j++) {
				if (j == i)
					s += 'Y';
				else
					s += 'N';
			}
			v[i] = s;
		}

		Graph g(n);
		for (int i = 1; i < n; i++) {
			if (in[i - 1] == out[i] && out[i] == 'Y')
				g.addEdges(i, i - 1);
			if (in[i] == out[i - 1] && out[i - 1] == 'Y')
				g.addEdges(i - 1, i);
		}

		g.dfs(v);
		/*
				for (int i = 0; i < n; i++) {
					cout << i << " : ";
					for (auto j : g.g[i])
						cout << j << " ";
					cout << endl;
				}*/

		for (int i = 0; i < n; i++) {
			cout << v[i] << endl;
		}
	}

	return 0;
}