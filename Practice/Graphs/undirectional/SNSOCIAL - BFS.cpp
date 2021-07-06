#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// https://www.codechef.com/problems/SNSOCIAL
// BFS
// Snakes and transition from Capitalism to Socialism

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int result() {
    int n, m;
    cin >> m >> n;
    vector<vector<int> > mat(m, vector<int>(n, 0));
    int mx = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            mx = max(mat[i][j], mx);
        }
    queue<pair<int, int>> Q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == mx)
                Q.push({i, j});
    int ans = 0 ;
    int lvl = 1;
    map<pair<int, int>, int> vis;
    while (!Q.empty()) {
        int size = Q.size();
        while (size--) {
            auto itr = Q.front();
            Q.pop();
            int i = itr.first, j = itr.second;
            if (vis[ {i, j}] != 0) continue;
            vis[ {i, j}] = lvl;
            ans = max(ans, lvl);
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x<0 or y< 0 or x >= m or y >= n or vis[ {x, y}] != 0)
                    continue;
                Q.push({x, y});
            }
        }
        lvl++;
    }
    // for (auto itr : vis) {
    //  cout << itr.first.first << " " << itr.first.second << " - " << itr.second << endl;
    // }

    return ans - 1;
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
        cout << result() << endl;
    }

    return 0;
}