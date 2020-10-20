#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

vector<int> parent;

int find(int x) {
    return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
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
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vector<pair<int, int>> ans;

        bool vis[n + 1];
        memset(vis, false, sizeof vis);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                for (int j = 1; j <= n; j++) {
                    if (arr[i] != arr[j]) {
                        ans.push_back({i, j});
                        vis[j] = true;
                    }
                }
                vis[i] = true;
            }
        }

        if (ans.size() < n - 1) {
            cout << "NO" << endl;
            continue;
        }
        parent.resize(n + 1);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        cout << "YES" << endl;

        //DSU for removing cycles
        sort(ans.begin(), ans.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < ans.size(); i++) {
            // cout << ans[i].first << " " << ans[i].second << endl;
            if (find(ans[i].first) != find(ans[i].second)) {
                unite(ans[i].first, ans[i].second);
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }

    return 0;
}