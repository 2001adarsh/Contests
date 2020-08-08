#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//https://codeforces.com/contest/1385/problem/E

vector<vector<int> > g;
vector<bool> vis;
vector<int> ord;

void dfs(int x) {
	vis[x] = true;
	for (auto nbr : g[x]) {
		if (!vis[nbr])
			dfs(nbr);
	}
	ord.push_back(x);
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		g = vector<vector<int> >(n);
		vector<pair<int, int> > edges;

		for (int i = 0; i < m; i++) {
			int k, x, y;
			cin >> k >> x >> y;
			x--; y--;
			if (k == 1) {
				g[x].push_back(y);
			}
			edges.push_back({x, y});
		}

		ord.clear();

		vis = vector<bool>(n);
		for (int i = 0; i < n; i++)
			vis[i] = false;

		for (int i = 0; i < n; i++) {
			if (!vis[i])
				dfs(i);
		}

		reverse(ord.begin(), ord.end());
		vector<int> pos(n);

		for (int i = 0; i < n; i++) {
			pos[ord[i]] = i;
		}

		//checking for cycle in current loop
		bool cycle = false;
		for (int i = 0; i < n; i++) {
			for (auto nbr :  g[i]) {
				if (pos[i] > pos[nbr]) cycle = true;
			}
		}
		if (cycle) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (auto p : edges) {
			if (pos[p.first] < pos[p.second])
				cout << p.first + 1  << " " << p.second + 1  << endl;
			else
				cout << p.second + 1 << " " << p.first + 1 << endl;
		}

	}


	return 0;
}