#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class Graph
{
	int V;
	vector<pair<int, int> > *adj;
public:
	vector<int> parent; //store parent. Helps in finding path

	Graph(int V) {
		this->V = V;
		adj = new vector< pair<int, int> >[V];
	}

	void addEdge(int x, int y, int w) {
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}

	void shortestPath(int src) { //Using Dijkstra's algorithm
		vector<int> dist(V, INT_MAX); //contain distances to all points. initialised with 0
		set<pair<int, int> > st; //to store nodes which is being processed.

		parent.resize(V);
		iota(parent.begin(), parent.end(), 0); //making each a parent of own

		dist[src] = 0;
		st.insert(make_pair(dist[src], src)); //dist of src is 0 now.

		while (!st.empty()) {
			//pop out minimum element and update the nbrs
			auto node = *(st.begin());
			st.erase(st.begin());

			for (auto nbr : adj[node.second]) {
				if (dist[nbr.first] > nbr.second + node.first) {
					parent[nbr.first] = node.second;
					//if smaller path value found then updation
					auto f = st.find(make_pair(dist[nbr.first], nbr.first));
					if (f != st.end())
						st.erase(f);
					dist[nbr.first] = nbr.second + node.first;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
		}

		for (int i = 0; i < V; ++i)
		{
			cout << i << " is distance away: " << dist[i] << endl;
		}
	}

	void findPath(int x) {
		if (x == parent[x])
			return;
		cout << x << " -> ";
		return findPath(parent[x]);
	}

};

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V = 9;
	Graph g(V);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

	g.findPath(8); //finds path from 0 to 8.

	return 0;
}