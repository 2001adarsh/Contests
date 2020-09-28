#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Floyd Warshall Algorithm.
/*
    -- All pair shortest path.
    -- Works with negative weights too
    -- DP  --O(N^3) time and O(N^2) space

putting all values in initial matrix, and from then in V phases, calculating the
distances keeping, the kth phases row and col same. and taking kth as intermediate
between two nodes.
*/
/*
For negative cycle. in the result, if the distance from itself to itself
is anything other than 0. then it has negative cycle.

*/

int INF = 10000;

vector<vector<int> > Floyd_Warshall(vector<vector<int> > graph) {
    vector<vector<int> > dist(graph);
    int V = graph.size();
    //Phases, in Kth phase we include vertices (1,2,3... k) as intermediate vertices.
    for (int k = 0; k < V; k++) {
        //Iterate over entire 2D matrix.
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
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

    vector<vector<int> > graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };

    auto result = Floyd_Warshall(graph);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            if (i == j && result[i][j] != 0) {
                cout << "Negative weight cycle";
                exit(0);
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
