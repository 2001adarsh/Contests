#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
//Knapsack 0-1 Problem
//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

void solve(int n, int val[], int wght[], int W) {
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j]; //not included
            if (j >= wght[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wght[i - 1]] + val[i - 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++)
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
    int values[n], weight[n];
    for (int i = 0; i < n; i++)
        cin >> values[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int W;
    cin >> W;

    solve(n, values, weight, W);

    return 0;
}