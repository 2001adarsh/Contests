#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-minimum-s-t-cut-in-a-flow-network/0#

const int N = 100;
int V;
int bfs(int rGraph[N][N], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

void dfs(int rGraph[N][N], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
        if (rGraph[s][i] && !visited[i])
            dfs(rGraph, i, visited);
}

// Prints the minimum s-t cut
void minCut(int graph[N][N], int s, int t)
{
    int u, v;
    int rGraph[N][N]; // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path
    bool flag = false;
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        flag = true;
    }

    if (!flag) {
        cout << -1 << " ";
        return;
    }

    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (visited[i] && !visited[j] && graph[i][j])
                cout << i << " " << j << " ";

    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> V;
        int arr[N][N];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cin >> arr[i][j];
            }
        }
        int source, sink;
        cin >> source >> sink;
        minCut(arr, source, sink);
        cout << endl;
    }
    return 0;
}

/*
1
6
0 16 13 0 0 0 0 0 10 12 0 0 0 4 0 0 14 0 0 0 9 0 0 20 0 0 0 7 0 4 0 0 0 0 0 0
0 5

output
1 3 4 3 4 5
*/