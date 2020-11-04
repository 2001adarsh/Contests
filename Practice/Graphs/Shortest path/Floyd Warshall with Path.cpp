#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
#define INF 1000000000000000000LL
/*
Finding shortest path between any two nodes using Floyd Warshall Algorithm

https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/?ref=rp

*/
int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 4;

	int V = 4;
	vector<vector<int> > graph
	= { { 0, 3, INF, 7 },
		{ 8, 0, 2, INF },
		{ 5, INF, 0, 1 },
		{ 2, INF, INF, 0 }
	};

	vector<vector<int> > dist = graph;
	vector<vector<int> > next(graph.size(), vector<int>(graph[0].size(), 0)); //To contain information of next node in the path.

	//in starting the value of next node will be either the next node or -1(if no direct edge)
	for (int u = 0; u < V; u++) {
		for (int v = 0; v < V; v++) {
			if (graph[u][v] != INF)
				next[u][v] = v;
			else
				next[u][v] = -1;
		}
	}

	//Floyd Warshall Algo
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF &&
				        dist[i][k] + dist[k][j] < dist[i][j]) {

					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k]; //next node will be the intermediate node.
				}
			}
		}
	}

	//Check for negative weight cycle
	bool cycle = false;
	for (int i = 0; i < n; i++)
		if (dist[i][i] < 0) {
			cout << "negative weight cycle!";
			cycle = true;
		}

	if (!cycle) {
		//find shortest path between any node to any node.
		//let
		int u = 3 , v = 2; //path from node 3 to 2.

		if (next[u][v] == -1) {
			cout << "No valid path";
		}
		else {
			vector<int> path = {u};
			while (u != v) {
				u = next[u][v];
				path.push_back(u);
			}
			for (int i = 0; i < path.size(); i++)
				cout << path[i] << " ";
		}
	}


	return 0;
}
