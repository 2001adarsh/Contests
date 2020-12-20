#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Minimum cost - Grid based DP

const int N = 100;

void shortPath(const int n, int cost[][N]) {
    int dp[N][N];
    dp[0][0] = cost[0][0];
    // parent[N][N]; this should be of type pair, to accomodate indices of parent.
    // parent[0][0] = -1; //can calculate parent;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {} //skip if 1st element
            else if (i == 0) {
                dp[i][j] = dp[i - 1][j] + cost[i][j];
                // parent[i][j] =
            }
            else if (j == 0)
                dp[i][j] = dp[i][j - 1] + cost[i][j];
            else
                dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1]) + cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int mat[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    shortPath( n, mat);

    return 0;
}