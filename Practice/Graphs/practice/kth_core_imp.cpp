#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

class Graph
{
	int V;
	list<int> *l;
public:

	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	//this is for whose degree is less than k, we reduce the degree of other elements too
	bool dfs(int node, vector<bool>& vis, vector<int>& degree, int k) {
		vis[node] = true;
		for (auto nbr : l[node]) {
			if (degree[node] < k) //if parent degree is less than k then, reduce it from every node thereafter.
				degree[nbr]--;

			if (!vis[nbr]) {
				if (dfs(nbr, vis, degree, k)) {
					degree[node]--;
				}
			}
		}
		return degree[node] < k;
	}

	void printKcores(int k) {
		int minDegree = INT_MAX , startVertex = 0;
		vector<bool> vis(V, false);
		vector<int> degree(V, 0);

		//initialising indegree
		for (int i = 0; i < V; i++) {
			degree[i] = l[i].size();
			if (degree[i] < minDegree) { //finding the lowest degree node to start from.
				minDegree = degree[i];
				startVertex = i;
			}
		}
		// cout << startVertex << endl;
		/*
				for (auto i : degree)
					cout << i << " ";
				cout << endl;*/

		dfs(startVertex, vis, degree, k);
		//for other unreachable nodes
		for (int i = 0; i < V; i++) {
			if (!vis[i])
				dfs(i, vis, degree, k);
		}

		/*		for (auto i : degree)
					cout << i << " ";
		*/
		for (int i = 0; i < V; i++) {
			if (degree[i] >= k) {
				cout << "[" << i << "] -> ";
				for (auto nbr : l[i]) {
					if (degree[nbr] >= k)
						cout << nbr << " ,";
				}
				cout << endl;
			}
		}
	}
};


int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k = 3;
	Graph g1(9);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 5);
	g1.addEdge(2, 3);
	g1.addEdge(2, 4);
	g1.addEdge(2, 5);
	g1.addEdge(2, 6);
	g1.addEdge(3, 4);
	g1.addEdge(3, 6);
	g1.addEdge(3, 7);
	g1.addEdge(4, 6);
	g1.addEdge(4, 7);
	g1.addEdge(5, 6);
	g1.addEdge(5, 8);
	g1.addEdge(6, 7);
	g1.addEdge(6, 8);

	g1.printKcores(k);


	return 0;
}