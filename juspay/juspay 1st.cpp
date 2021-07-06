#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18

unordered_map<int, vector<int>> mp;
unordered_map<int, bool > vis;

bool dfs(int node, int target) {
    vis[node] = true;
    if (node == target)
        return true;
    for (int nbr : mp[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, target))
                return true;
        }
    }
    return false;
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int a, b;
    cin >> a >> b;
    if (dfs(a, b))
        cout << 1;
    else cout << 0;


    return 0;
}