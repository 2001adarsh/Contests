#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

class Graph
{
    int V;
    vector<int> *gr;
public:

    vector<int> special;

    Graph(int V) {
        this->V = V;
        gr = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    void spec(int x) {
        special.push_back(x);
    }

    void bfs(int src) {
        vector<int> dist(V + 1, INT_MAX);
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            for (auto nbr : gr[node]) {
                if (dist[nbr] == INT_MAX) {
                    Q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < special.size(); i++) {
            ans = min(ans, dist[special[i]]);
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g.addEdge(u, v);
        }
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            x--;
            g.spec(x);
        }
        int query;
        cin >> query;
        for (int i = 0; i < query; i++) {
            int x;
            cin >> x; x--;
            g.bfs(x);
        }
    }

    return 0;
}