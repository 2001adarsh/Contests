#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define MAXN 100000
#define level 18

// https://www.geeksforgeeks.org/lca-for-general-or-n-ary-trees-sparse-matrix-dp-approach-onlogn-ologn/
// only precomuting of lca seen from geeksforgeeks.

vector<int> dist;
vector<int> depth;
int parent[MAXN][level];

void dfs(vector<pair<int, int> > adj[], int x, int prev) {
    depth[x] = depth[prev] + 1;
    parent[x][0] = prev;

    for (auto nbr : adj[x]) {
        if (nbr.first != prev) {
            dist[nbr.first] = dist[x] + nbr.second;
            dfs(adj, nbr.first, x);
        }
    }
}

void precomputeSparseMatrix(int n)
{
    for (int i = 1; i < level; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (parent[node][i - 1] != -1)
                parent[node][i] =
                    parent[parent[node][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 0; i < level; i++)
        if ((diff >> i) & 1)
            v = parent[v][i];

    if (u == v)
        return u;
    for (int i = level - 1; i >= 0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}

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
        int n, q, r;
        cin >> n >> q >> r;
        vector<pair<int, int> > gr[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }

        dist.assign(n + 1, INT_MAX);
        depth.assign(n + 1, 0);
        memset(parent, -1, sizeof(parent));


        depth[0] = 0;
        dist[r] = 0;
        dfs(gr, r, 0);
        precomputeSparseMatrix(n);


        while (q--) {
            int u, v;
            cin >> u >> v;
            int least = lca(u, v);
            cout << (dist[u] - dist[least]) + (dist[v] - dist[least]) << endl;
        }
    }

    return 0;
}