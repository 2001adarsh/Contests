#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
/* Ford Fulkerson Algorithm:

1> The flow <= capacity
2> The flow[in] = flow[out] for every vertex except source(S) and sink(T).

Algorithm:

-> Setup the directed residual graph with edge capacity = original graph.
-> Initialise the variable MAX_FLOW =  0
-> Loop
        while(there exists an augmented path from S to T){
            -> Find 'f' ie, minimum edge in the current augmented path.
            -> Decrease the capacity of all forward edges and
                Increase the capacity of all backward edges.
            -> MAX_FLOW += f
        }
-> Print MAX_FLOW

For finding the augmented path, we use BFS. and usage of BFS in
Ford Fulkerson Algorithm,
makes the algorithm named as Edmund Karp Algorithm.

According to MaxFlow-MinCut Algorithm,
the amount of max flow = min cut in a network graph.
*/

bool bfs(int **residualCapacity, int source, int sink, int *parent, int n) {
    bool visited[n];
    memset(visited, false, sizeof visited);

    queue<int> Q;
    Q.push(source);
    visited[source] = true;
    bool foundAugmentedPath = false;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < n; v++) {
            if ( (visited[v] == false) && (residualCapacity[u][v] > 0)) {
                parent[v] = u;
                Q.push(v);
                visited[v] = true;
                if (v == sink) {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugmentPaths(vector<vector<int>> paths) {
    for (int i = 0; i < paths.size(); i++) {
        for (int j = 0; j < paths[i].size(); j++)
            cout << paths[i][j] << ", ";
        cout << endl;
    }
}

int maxFlow(int **capacity, int source, int sink, int n) {
    //create a residual capacity graph.
    int **residualCapacity = new int*[n];
    for (int i = 0; i < n; i++) {
        residualCapacity[i] = new int[n];
    }
    int MAX_FLOW = 0; //our ans.

    //first init residual to original capacity graph.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            residualCapacity[i][j] = capacity[i][j];
    }

    int *parent = new int[n + 1]; //to store the parent
    vector<vector<int>> augmentedPaths; //to store all kinds of path.

    while (bfs(residualCapacity, source, sink, parent, n)) { //if there is a path.
        vector<int> currentPath;
        int flow = INT_MAX;
        int v = sink;
        while (v != source) {
            currentPath.push_back(v);
            int u = parent[v];
            flow = min(residualCapacity[u][v], flow);
            v = u;
        }
        currentPath.push_back(source);

        //flow subtract
        v = sink;
        while (v != source) {
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
        }

        reverse(currentPath.begin(), currentPath.end());
        augmentedPaths.push_back(currentPath);
        MAX_FLOW += flow;
    }
    printAugmentPaths(augmentedPaths);
    return MAX_FLOW;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, edges;
    cin >> v >> edges;

    //init of edge capacity
    int **capacity = new int*[v];
    for (int i = 0; i < v; i++)
        capacity[i] = new int[v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            capacity[i][j] = 0;
    }

    for (int i = 0; i < edges; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }
    int source, sink;
    cin >> source >> sink;
    cout << maxFlow(capacity, source, sink, v);

    return 0;
}

/*

5 7
0 2 100
0 3 50
3 4 100
2 3 50
2 1 50
4 1 125
2 4 50
0 1

*/