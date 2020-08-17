#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll
const int N = 100005;
class Graph
{
public:
    map<int , list<int>> adj;
    vector<bool> vis;
    Graph() {
        vis.assign(N, false);
    }

    void addEdge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cnt = 0;
    void dfs(int x, int y) {
        if (x == y)
            return;
        vis[x] = true;
        cnt++;
        for (auto i : adj[x]) {
            if (!vis[i])
                dfs(i, y);
        }
    }
    int bfs(int src, int dest) {
        map<int, int> dist;
        queue<int> q;

        for (auto pair_num : adj) {
            dist[pair_num.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;  //starting src with 0 level.

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nbr : adj[node]) {
                if (dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        return dist[dest];
    }

};

int largestFactor(int num) {
    if (num % 2 == 0)
        return num / 2;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return num / i;
    }
    return 1;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;
    int orga = a, orgb = b;
    Graph g;
    int geta = largestFactor(a);
    int getb = largestFactor(b);

    while (geta > 1) {
        //  cout << a << " " << geta << endl;
        g.addEdge(a, geta);
        a = geta;
        geta = largestFactor(geta);
    }
    g.addEdge(a, 1);

    while (getb > 1) {
        g.addEdge(b, getb);
        b = getb;
        getb = largestFactor(getb);
    }
    g.addEdge(b, 1);

    cout << g.bfs(orga, orgb);
    return 0;
}