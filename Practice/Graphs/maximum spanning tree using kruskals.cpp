#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Maximum Spanning Tree. using kruskals

class DSU
{
public:
    int V;
    vector<int> parent;
    vector<int> size;
    DSU();
    DSU(int V) {
        this->V = V;
        parent.resize(V);
        size.resize(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x];
                size[x] = 0;
            } else {
                parent[y] = x;
                size[x] += size[y];
                size[y] = 0;
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

    int V, E;
    cin >> V >> E;
    vector<vector<int> > edges;
    for (int i = 0; i < E; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, x, y});
    }
    sort(edges.begin(), edges.end(), greater<vector<int>>());

    int maximumMST = 0;
    //create DSU.
    DSU dsu(V);
    for (int i = 0; i < E; i++) {
        int x = edges[i][1], y = edges[i][2], w = edges[i][0];
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            maximumMST += w;
        }
    }

    cout << maximumMST;

    return 0;
}