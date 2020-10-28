#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int> > edgeList;
    int n, m;
    cin >> m >> n; //number of edges - n;
    for (int i = 0; i < n; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edgeList.push_back({u, v, wt});
    }

    vector<int> dist(m + 1, INT_MAX);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edgeList) {
            if (dist[e[0]] + e[2] < dist[e[1]])
                dist[e[1]] = dist[e[0]] + e[2];
        }
    }

    int flag = false;
    for (auto e : edgeList) { //Negative cycle checking.
        if (dist[e[0]] + e[2] < dist[e[1]]) {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "-1" << endl;
    else
        for (int i = 1; i <= m; i++)
            cout << dist[i] << " ";


    return 0;
}

/*
5 8
1 2 -1
1 3 4
2 5 2
5 4 -3
4 3 5
4 2 1
2 4 2
2 3 3
*/