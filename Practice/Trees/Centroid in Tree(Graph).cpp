#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Centroid of Tree - Like Graph.
const int N = 1e5;
set<int> gr[N];
int n, m;

void bfs(vector<int> centroids) {
    queue<int> Q;
    for (auto x : centroids)
        Q.push(x);

    vector<int> here;
    int cnt = Q.size(), nextRound = 0;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (auto nbr : gr[node]) {
            gr[nbr].erase(node);
            if (gr[nbr].size() == 1) {
                Q.push(nbr);
                nextRound++;
                here.push_back(nbr);
            }
        }
        cnt--;
        if (!cnt and !Q.empty()) {
            cnt = nextRound;
            nextRound = 0;
            centroids = here;
            here.clear();
        }
    }

    for (auto x : centroids)
        cout << x << " ";
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].insert(y);
        gr[y].insert(x);
    }
    for (int i = 0; i < n; i++) {
        for (auto x : gr[i])
            cout << x << " ";
        cout << endl;
    }
    vector<int> centroids;
    for (int i = 0; i < n; i++) {
        if (gr[i].size() == 1)
            centroids.push_back(i);
    }

    bfs(centroids);

    return 0;
}
// For the tree-alike graph, the number of centroids is no more than 2.