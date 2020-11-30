#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int dp[1005][1005];


//Time complexity - O(N * N^2( as there are 2 states)) -> O(N^3)
int fun(int arr[], int i, int j) {
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    //recursive case
    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int left = fun(arr, i, k);
        int right = fun(arr, k + 1, j);
        int current = arr[i - 1] * arr[k] * arr[j];

        minCost = min(minCost , left + right + current);
    }
    return dp[i][j] = minCost;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {10, 20, 30};
    int n = sizeof (arr) / sizeof (int);
    memset(dp, -1, sizeof dp);
    cout << fun(arr, 1, n - 1);

    return 0;
}