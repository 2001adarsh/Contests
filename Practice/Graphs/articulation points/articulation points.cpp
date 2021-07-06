#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Articulation Points.

vector<vector<int>> gr;
vector<int> in, low;
vector<bool> AP; // Articulate points.
int timer = 0;

void dfs(int x, int par = -1) {
    in[x] = low[x] = timer++;
    int children = 0;
    for (auto nbr : gr[x]) {
        if (in[nbr] == -1) { // not visited.
            dfs(nbr, x);
            low[x] = min(low[x], low[nbr]);

            if (par == -1) // counting number of dfs subtree that can be formed.
                children++;

            if (par != -1 and low[nbr] >= in[x])
                AP[x] = true;

        } else if (in[nbr] != -1 and nbr != par) { // already visited &  not pointing to parent.
            //backedge
            low[x] = min(low[x], in[nbr]);
        }
    }

    //for root to be artication point,
    if (par == -1 and children > 1)
        AP[x] = true;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int V, E;
    cin >> V >> E;

    gr.assign(V, {});
    in.assign(V, -1);
    low.assign(V, -1);
    AP.assign(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (in[i] == -1)
            dfs(i);
    }

    for (int i = 0; i < V; i++)
        cout << AP[i] << " ";

    return 0;
}