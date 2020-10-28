#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define INF 1000000000000000000LL

/*
Floyd Warshall Algorithm
- use a matrix(2D array)
- [0...k] means that k vertices are being considered as intermediate vertices.
- DP solution.
-O(V^3).
- We can modify the solution to print the shortest paths also by storing the predecessor information in a separate 2D matrix.
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 4;

    int graph[][n] = { {0,   5,  INF, 10},
        {INF,  0,  3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    //can also make a dist[][] and initialise same value as of graph.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == k || j == k || i == j)
                    continue;
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}


/*
To avoid integer overflow-
#include
#define INF INT_MAX
..........................
if ( dist[i][k] != INF &&
     dist[k][j] != INF &&
     dist[i][k] + dist[k][j] < dist[i][j]
    )
 dist[i][j] = dist[i][k] + dist[k][j];
...........................

*/