#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18

vector<vector<int>> capacity; //residual capacity
vector<vector<int>> adj; // graph
// adj is the adjacency list of the undirected graph,
// since we have also to use the reversed of directed edges when we are looking for augmenting paths.

int bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int> > Q;

    parent[source] = -2;
    Q.push({source, inf} );//{u, flow}

    while (!Q.empty()) {
        auto top = Q.front();
        Q.pop();

        int flow = top.second;
        for (auto nbr : adj[top.first]) {
            if (parent[nbr] == -1 and capacity[top.first][nbr]) {
                flow = min(flow, capacity[top.first][nbr]);
                parent[nbr] = top.first;

                if (nbr == target)
                    return flow;
                Q.push({nbr, flow});
            }
        }
    }
    return 0;
}

int maxFlow(int source, int target, int n) {
    vector<int> parent(n);
    int max_flow = 0; //maximum flow;

    int new_flow;
    while (new_flow = bfs(source, target, parent)) {
        max_flow += new_flow;
        int t = target;
        cout << t << " ";
        while (t != source) {
            cout << parent[t] << " ";
            capacity[parent[t]][t] -= new_flow;
            capacity[t][parent[t]] += new_flow;
            t = parent[t];
        }
        cout << " -> " << new_flow << endl;
    }
    return max_flow;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    capacity.assign(n, vector<int>(n, 0));
    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int x, y, cap;
        cin >> x >> y >> cap;

        capacity[x][y] = cap;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int src, target;
    cin >> src >> target;

    cout << maxFlow(src, target, n);

    return 0;
}

/*
6 9
0 1 7
0 4 4
1 2 5
1 3 3
4 1 3
4 3 2
3 2 3
2 5 8
3 5 5
0 5
*/