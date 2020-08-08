#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//Prims Algorithm

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > gr[n + 1];
	int vis[n + 1] = {}; //visited array

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > Q;

	Q.push({0, 1}); //adding first node
	//{weight, node}
	int mst = 0;

	while (!Q.empty()) {
		pair<int, int> best = Q.top();
		Q.pop();

		int node = best.second;
		int weight = best.first;
		// not an active edge.
		if (vis[node]) continue;

		vis[node] = 1;
		mst += weight;
		//updating neighbours
		for (auto nbr : gr[node]) {
			if (!vis[nbr.first]) {
				// nbr.first is not visited
				Q.push({nbr.second, nbr.first});
			}
		}
	}
	cout << mst;

	return 0;
}