#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
const int INF = 10000000000000LL;

class Graph
{
	int V;
	vector<pair<int, int> > *gr;

public:
	vector<int> par;
	Graph(int V) {
		this->V = V;
		gr = new vector<pair<int, int>>[V];
	}

	void addEdge(int x, int y, int w) {
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	int dijskra(int src) {
		par.clear();
		par.resize(V);
		iota(par.begin(), par.end(), 0);

		int vis[V + 1] = {};
		vector<int> dist(V, INF);

		//{weight, node}
		set<pair<int, int> > st;
		st.insert({0, src});
		dist[src] = 0;

		while (!st.empty()) {
			auto best = *(st.begin());
			st.erase(st.begin());

			int node = best.second;
			int weightT = best.first;

			if (vis[node]) continue;
			vis[node] = 1;

			//updating neighbours
			for (auto nbr : gr[node]) {
				if ( !vis[nbr.first] && nbr.second + weightT < dist[nbr.first]) {
					//update the distance
					auto f = st.find({dist[nbr.first], nbr.first});
					if (f != st.end())
						st.erase(f);
					dist[nbr.first]  = nbr.second + weightT;
					st.insert({dist[nbr.first], nbr.first});

					//update parent
					par[nbr.first]  = node;
				}
			}
		}
		return dist[V - 1];
	}

	vector<int> findPath(int s, int t) {
		vector<int> path;
		for (int i = t; i != s; i = par[i])
			path.push_back(i);
		path.push_back(s);
		reverse(path.begin(), path.end());
		return path;
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
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		g.addEdge(x, y, w);
	}

	int k = g.dijskra(0);
	if (k == INF) {
		cout << "-1" << endl;
	} else {
		vector<int> v = g.findPath(0, n - 1);
		for (auto i : v) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}