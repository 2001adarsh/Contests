#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

/*
Field of Dreams.

2D grid of NxM, each cell has 0 or 1, we have to disconnect 1's from each other(atleast 1 disconnected)
If already disconnected, then print 0.
Else print minimum number of 1's node to make 0's to make 1's disconnected.
*/

vector<vector<int>> matrix;
vector<vector<int>> gr;
map<pair<int, int>, int> toSingle;
int curr = 0;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& gr) {
    vis[node] = true;
    for (auto nbr : gr[node])
        if (!vis[nbr])
            dfs(nbr, vis, gr);
}

//articulation points.
vector<int> dfsNum, low;
int cnt = 1;
int articulationPoints = 0;

void run(int node, int par, vector<vector<int>>& gr) {
    dfsNum[node] = low[node] = cnt++;
    int child = 0;
    for (auto nbr : gr[node]) {
        if (dfsNum[nbr] == 0) {
            child++;
            run(nbr, node, gr);
            low[node] = min(low[node], low[nbr]);
            if (node != 0 and low[nbr] >= dfsNum[node]) {
                articulationPoints++; //node is an articulation points.
                cout << "point: " << node << endl;
            }
        } else if (par != nbr)
            low[node] = min(low[node], dfsNum[nbr]);
    }
    if (node == 0 and child > 1)
        articulationPoints++; //root is an articulation points.
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> m >> n;
    matrix.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                toSingle[ {i, j}] = curr;
                curr++;
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    //creating graph.
    gr.resize(curr + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int newi = dx[k] + i, newj = dy[k] + j;
                    if (newi<0 or newj<0 or newi >= m or newj >= n or matrix[newi][newj] == 0)
                        continue;
                    gr[toSingle[ {i, j}]].push_back(toSingle[ {newi, newj}]);
                }
            }
        }
    }

    //graph
    // for (int i = 0; i < curr; i++) {
    //  cout << i << "->";
    //  for (auto itr : gr[i])
    //      cout << itr << " ";
    //  cout << endl;
    // }

    //checking if already disconnected.
    int connectedComp = 0;
    vector<bool> vis(curr, false);
    for (int i = 0; i < curr; i++) {
        if (vis[i] == false) {
            dfs(i, vis, gr);
            connectedComp++;
        }
    }

    if (connectedComp == 0 or connectedComp > 1) {
        cout << "0"; //means already disconnected.
        return 0;
    }

    //find articulation points.
    dfsNum.assign(curr, 0);
    low.assign(curr, 0);

    run(0, -1, gr);

    for (int i = 0; i < curr; i++) {
        cout << i << " -" << dfsNum[i] << " " << low[i] << endl;
    }

    if (articulationPoints > 0)
        cout << "1"; //means we can remove 1 node to make more components.
    else cout << "2"; //there can be two disconnected nodes;


    return 0;
}

/*
3 3
1 0 1
1 0 1
1 1 1

*/