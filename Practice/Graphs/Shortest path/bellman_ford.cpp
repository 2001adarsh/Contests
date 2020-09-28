#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"

//Bellman Ford Algorithm: O(VE)
/*
    1. Initialise the dist[vertices] = INT_MAX and dist[src] = 0
    2. Relax all edges (V - 1) times
    3. Negative weight cycle (check if V-1th dist changes while Vth iteration)
*/
vector<vector<int> > edges;

vector<int> bellman_ford(int src, int V) {
    vector<int> dist(V + 1, INT_MAX);
    dist[src] = 0;

    //Relax all edges V-1 times.
    for (int i = 0; i < V - 1; i++) {

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            //Relaxing
            if ( dist[u] != INT_MAX and dist[v] > dist[u] + wt) //to also avoid overflow.
                dist[v] = dist[u] + wt;
        }
    }
    //Check for negative weight cycle.
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        //if true then exit.
        if (dist[u] != INT_MAX and dist[v] > dist[u] + wt) {
            cout << "Negative weight cycle.";
            exit(0);
        }
    }
    return dist;
}

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
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<int> distances = bellman_ford(1, n);
    for (int i = 0; i < n; i++) {
        cout << "For node " << i << " the dist is: " << distances[i] << endl;
    }

    return 0;
}


/*
3 3
1 2 2
2 3 -4
3 1 1
for negative wt cycle.

9 14
0 1 4
1 2 8
0 7 8
1 7 11
7 8 7
7 6 1
6 8 6
2 8 2
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
for normal output.
*/