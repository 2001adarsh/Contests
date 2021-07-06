#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 998244353
#define inf 1e18

/*
1093 D. Beautiful Graph

You are given an undirected unweighted graph consisting of n vertices and m edges.

You have to write a number on each vertex of the graph. Each number should be 1, 2 or 3. The graph becomes beautiful if for each edge the sum of numbers on vertices connected by this edge is odd.

Calculate the number of possible ways to write numbers 1, 2 and 3 on vertices so the graph becomes beautiful. Since this number may be large, print it modulo 998244353.

Note that you have to write exactly one number on each vertex.

The graph does not have any self-loops or multiple edges.
*/

int cnt_1, cnt_2, can;
void dfs(int node, vector<vector<int>>& gr, vector<int>& col, int c) {
    col[node] = c;
    if (c == 1)
        cnt_1 ++;
    else cnt_2++;

    for (auto nbr : gr[node]) {
        if (!col[nbr])
            dfs(nbr, gr, col, 3 - c);
        else if (col[nbr] == col[node])
            can = false;
    }

}

int power(int x, unsigned int y)
{
    int temp;
    if ( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return (temp * temp) % mod;
    else
        return (x * temp * temp) % mod;
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> gr(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        int ans = 1;
        vector<int> vis(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt_1 = cnt_2 = 0;
                can = true;
                dfs(i, gr, vis, 1);

                if (can == false) {
                    ans = 0;
                    break;
                }

                int total = power(2, cnt_1)  + power(2, cnt_2);
                ans = (ans  * total ) % mod;
            }
        }
        cout << ans << endl;
    }



    return 0;
}