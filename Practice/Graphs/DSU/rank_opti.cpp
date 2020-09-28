#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
vector<int> par;
vector<int> rankt;

// Rank optimisation -- The bigger tree is made parent of smaller tree
// in Unite function.
struct DSU
{
    int find(int x) {
        if (par[x] == -1)
            return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
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
        else return true;
        return false;
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
        par[i] = -1;
    }

    bool ans = false;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ans = ans || dsu.unite(x, y);
    }
    cout << ans << endl;

    //Parent array
    for (int i = 0; i < n; i++)
        cout << par[i] << " ";
    //Rank array
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << rankt[i] << " ";
    return 0;
}