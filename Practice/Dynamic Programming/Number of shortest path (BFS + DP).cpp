#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Number of Shortest paths
// https://atcoder.jp/contests/abc211/tasks/abc211_d

/*
How many paths are there in which you can get from City 1 to City N as early as possible?
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> dist(n, inf); //Smallest dist till 'i'
    vector<int> cnt(n, 0); //Number of smaller paths till 'i'

    queue<int> Q;
    Q.push(0);
    dist[0] = 0, cnt[0] = 1;

    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for (auto nbr : gr[top]) {
            if (dist[nbr] == inf) {
                dist[nbr] = dist[top] + 1;
                cnt[nbr] = cnt[top]; //same paths going forward.
                Q.push(nbr);
            } else if (dist[nbr] == dist[top] + 1) //if already visted, and takes same amount of time to reach here also. Another path found.
                (cnt[nbr] += cnt[top] ) %= mod;
        }
    }

    //paths required to reach last node
    cout << cnt[n - 1];


    return 0;
}