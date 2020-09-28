#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"

const int N = 10005;
vector<pair<int, int> > gr[N];

// It is different from Set in a way that, we do not update the node like we do in
// set but rather insert a copy of the update node back in the priority_queue.
//This makes multiple instances of the same node in the priority_queue, which gets
// popped out at last.

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[x].push_back({y, w});
        gr[y].push_back({x, w});
    }

    int ans = 0;
    vector<int> dist(n + 1, INT_MAX);

    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > Q;
    Q.push({0, 0});
    dist[0] = 0;

    while (!Q.empty()) {
        auto best = Q.top();
        Q.pop();
        int node = best.second;

        for (auto nbr : gr[node]) {
            int w = nbr.second;
            if (dist[nbr.first] > dist[node] + w) {
                dist[nbr.first] = dist[node] + w;
                Q.push({dist[nbr.first], nbr.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << endl;

    return 0;
}