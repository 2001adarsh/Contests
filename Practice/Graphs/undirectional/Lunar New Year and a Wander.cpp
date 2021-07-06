#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// https://codeforces.com/problemset/problem/1106/D

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<bool> vis(n + 1);
    vector<int> path;

    priority_queue<int, vector<int>, greater<int> > Q;
    Q.push(1);

    while (!Q.empty()) {
        int u = Q.top();
        Q.pop();
        if (vis[u] == true)
            continue;
        vis[u] = true;
        path.push_back(u);
        for (auto i : gr[u])
            Q.push(i);
    }

    for (auto i : path)
        cout << i << " ";

    return 0;
}