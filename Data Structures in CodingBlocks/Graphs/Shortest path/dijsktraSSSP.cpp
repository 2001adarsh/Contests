#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

template <typename T>
class Graph
{
	unordered_map < T, list<pair<T, int>> > m;
public:

	void addEdges(T u, T v, int distance, bool bidir = true) {
		m[u].push_back(make_pair(v, distance));
		if (bidir) {
			m[v].push_back(make_pair(u, distance));
		}
	}

	void printAdj() {
		//Printing the adjacency list
		for (auto j : m) {
			cout << j.first << " -> ";
			for (auto nbr : j.second)
				cout << nbr.first << " " << nbr.second << ", ";
		}
	}

	void dijsktraSSSP(T src) {
		unordered_map<T, int> dist;
		//set all distance to infinity initially
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}
		dist[src] = 0; //starting node to zero

		//make a set of pairs to find out one with minimum distance.
		set<pair<int, T> > s; //sorting according to first param.

		s.insert(make_pair(0, src));

		while (!s.empty()) {
			//find pair at front
			auto p = *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin()); //pop out the found node

			//iterate over nbrs of current node
			for (auto childPair : m[node]) {
				if (childPair.second + nodeDist < dist[childPair.first]) {

					//since updation is not possible so i have to erase and insert new value to simulate updation
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end())
						s.erase(f);
					dist[dest] = childPair.second + nodeDist;

					s.insert(make_pair(dist[dest], dest));
				}
			}
		}

		//printing final distances
		for (auto i : dist) {
			cout << i.first << " is located at distance : " << i.second << endl;
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

	Graph<int> g;
	g.addEdges(1, 2, 1);
	g.addEdges(1, 3, 4);
	g.addEdges(3, 4, 2);
	g.addEdges(2, 3, 1);

	g.dijsktraSSSP(1);

	return 0;
}