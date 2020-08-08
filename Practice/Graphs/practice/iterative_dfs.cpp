#include<bits/stdc++.h>
using namespace std;
#define int long long int
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

	void dfs() {
		stack<int> st;
		vector<bool> vis(V + 1, false);

		int node = 0;
		st.push(node);

		while (!st.empty()) {
			int top = st.top();
			st.pop();

			if (!vis[top]) {
				cout << top << " ";
				vis[top] = true;
			}

			for (auto nbr : l[top]) {
				if (!vis[nbr])
					st.push(nbr);
			}
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


	Graph g(5); // Total 5 vertices in graph
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 4);

	g.dfs();

	return 0;
}