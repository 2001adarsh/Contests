#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18
// DP on Graphs
// Basis for articulation point.
// Find the smallest height of a node that can be visited from subtree of x.


const int N = 1e5 + 5;
vector<int> gr[N];

vector<int> vis;
vector<int> shght;
vector<int> depth;

void dfs(int curr, int par, int level) {
    vis[curr] = 1;
    shght[curr] = level;
    depth[curr] = level;

    for (int x : gr[curr])
        if (vis[x] == 0) {
            dfs(x, curr, level + 1);
            shght[curr] = min(shght[curr], shght[x]); //smallest in subtree
        } else if (x != par)
            shght[curr] = min(shght[curr], depth[x]); //backedge
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
    vis.assign(N, 0);
    shght.assign(N, -1);
    depth.assign(N, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, -1, 0); //root at 1.

    for (int i = 1; i <= n; i++)
        cout << i << " " << shght[i] << endl;

    return 0;
}

/*
12 16
1 3
1 5
1 6
1 9
3 6
3 5
3 7
5 7
3 8
6 2
2 8
2 4
4 10
9 12
12 11
11 9
*/