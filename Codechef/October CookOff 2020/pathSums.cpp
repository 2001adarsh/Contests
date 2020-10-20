#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int N = 1005;
int visited[1005];
void dfs(int x, int col, vector<int> gr[N]) {
    visited[x] = col;
    for (auto nbr : gr[x]) {
        if (!visited[nbr]) {
            dfs(nbr, 3 - col, gr);
        }
    }
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
        memset(visited, 0, sizeof visited);
        int n;
        cin >> n;
        vector<int> gr[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        dfs(1, 1, gr);
        for (int i = 1; i <= n; i++)
            cout << visited[i] << " ";
        cout << endl;
    }
    return 0;
}