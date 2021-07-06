#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

void usingStack(vector<vector<int>>& gr, int src, vector<int>& vis) {
    cout << "Iterative DFS: ";
    vis.clear();
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int size = st.size();
        while (size--) {
            int top = st.top();
            st.pop();
            if (vis[top]) continue;
            cout << top << " ";
            vis[top] = 1;

            for (auto nbr : gr[top])
                st.push(nbr);
        }
    }
    cout << endl;
}

void recurseDFS(vector<vector<int>>& gr, int src, vector<int>& vis) {
    vis[src] = 1;
    cout << src << " ";
    for (auto nbr : gr[src]) {
        if (!vis[nbr])
            recurseDFS(gr, nbr, vis);
    }
}

void iterativeBFS(vector<vector<int>>& gr, int src, vector<int>& vis) {
    cout << "BFS: ";
    queue<int> Q;
    Q.push(src);
    while (!Q.empty()) {
        int size = Q.size();
        while (size--) {
            int top = Q.front();
            Q.pop();
            if (vis[top]) continue;
            vis[top] = 1;
            cout << top << " ";
            for (auto nbr : gr[top])
                Q.push(nbr);
        }
    }
    cout << endl;
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
    vector<vector<int>> gr(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }
    vector<int> vis(n);

    //DFS
    usingStack(gr, 0, vis);
    vis.clear();
    vis.resize(n);
    cout << "Recursive DFS: ";
    recurseDFS(gr, 0, vis);
    cout << endl;

    vis.clear();
    vis.resize(n);
    //BFS
    iterativeBFS(gr, 0, vis);

    return 0;
}

/*
6 8
0 1
0 2
2 5
1 5
1 2
1 3
3 4
5 4
*/