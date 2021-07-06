#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// Tree Queries
// https://codeforces.com/problemset/problem/1328/E
// Check if there is a path which involves nodes, or if not, then it should be
// atleast 1 distance away from the path. If such path is present print "YES".

// Using concept of Euler, for checking if node in path is ancestor or not.
// if a child of n, belongs to path, then n will also belong to the path and parent[n] will also
//belong to the path.

vector<vector<int> > gr;
vector<int> in, out, level, parent;
int timer = 1;
void dfs(int node, int par = -1, int lvl = 0) {
    level[node] = lvl;
    parent[node] = par;
    in[node] = timer++;

    for (auto nbr : gr[node]) {
        if (nbr != par)
            dfs(nbr, node, lvl + 1);
    }
    out[node] = timer++;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;

    gr.resize(n + 1);
    in.assign(n + 1, 0);
    out.resize(n + 1);
    level.resize(n + 1);
    parent.resize(n + 1);

    timer = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << i << " - " << in[i] << " " << out[i] << endl;

    while (q--) {
        int k;
        cin >> k;
        int arr[k];
        int deapest = -1, depNd = -1;
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
            if (deapest < level[arr[i]])
                deapest = level[arr[i]], depNd = arr[i];
            arr[i] = parent[arr[i]]; //parent will always lie in the path.
        }
        bool flag = false;
        for (int i = 0; i < k; i++) {
            if (arr[i] == -1) //parent of root node -> root node will always lie in path.
                continue;
            if (in[arr[i]] > in[depNd] or out[arr[i]] < out[depNd]) {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << "YES" << endl;
    }

    return 0;
}