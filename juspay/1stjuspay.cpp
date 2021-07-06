#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
int n, m, t , c ;
vector<vector<int>> gr;

int shortestPath(int src, int dest) {
    int lvl = -1;
    queue<int> Q;
    Q.push(src);
    vector<int> vis(dest + 1, 0);
    while (!Q.empty()) {
        int size = Q.size();
        lvl++;
        while (size--) {
            int u = Q.front();
            Q.pop();
            if (u == dest)
                return lvl;
            if (vis[u]) continue;
            vis[u] = true;
            for (auto nbr : gr[u])
                Q.push(nbr);
        }
    }
    return -1;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m >> t >> c;
    gr.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    int k =  shortestPath(1, n);
    cout << "Shortest Path: " << k << endl;
    // k = 3;
    int total = 0;
    for (int i = 0; i < k - 1; i++) {
        total += c;
        int temp = total / t;
        if ( temp % 2 == 1) {
            total = (temp + 1) * t;
        }
    }
    total += c;
    cout << total;

    return 0;
}