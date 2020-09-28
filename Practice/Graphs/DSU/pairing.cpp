#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
vector<int> par;
vector<int> rankt;

//Pairing. Making combinations of nodes of different set.

struct DSU
{
    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rankt[x] >= rankt[y]) {
                par[y] = x;
                rankt[x] += rankt[y];
            } else {
                par[x] = y;
                rankt[y] += rankt[x];
            }
        }
    }
};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    DSU dsu;
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    rankt.resize(n + 1);
    for (int i = 0; i < n; i++) {
        rankt[i] = 1;
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += n - rankt[dsu.find(i)];
    }
    cout << ans / 2;

    return 0;
}