#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18
//Travelling salesman problem ->


//dfs for finding best route, after randomly selecting 1 source. I will take first node
//that is 0.
//using mask to denote if curr city is visited or not.
int n, m;
vector<vector<int>> gr; //adjacency matrix;
vector<vector<int>> dp;
int final_mask;

int getMinPath(int mask, int curr) {
    if ( mask == final_mask)
        return ((gr[curr][0] != -1) ? gr[curr][0] : inf);

    if (dp[curr][mask] != -1)
        return dp[curr][mask];

    int path_sum = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (gr[curr][i] != -1 and ((1 << i) & mask) == 0) //and not visited
            path_sum = min(path_sum, gr[curr][i] + getMinPath( (1 << i) | mask, i));
    }

    return dp[curr][mask] = path_sum;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m;

    final_mask = (1 << n) - 1;
    gr.assign(n, vector<int>(n, -1));
    dp.assign(n, vector<int>(1 << n, -1));

    for (int i = 0; i < n; i++) //distace to itself should be zero
        gr[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[x][y] = w;
        gr[y][x] = w;
    }

    //inputed graph.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << gr[i][j] << " ";
        cout << endl;
    }


    //minimum path
    cout << getMinPath(1, 0);



    return 0;
}