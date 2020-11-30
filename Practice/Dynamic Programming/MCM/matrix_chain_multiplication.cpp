#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Matrix Chain Multiplication:
/*
Given the dimensions of matrices, and find the minimum cost required to compute
the multiplication of those matrix.

cost could be found as :
 A -> 2x 3
 B -> 3 x 4

 then cost -> 2x 3 x4

 so compute for what all combinations min. could be found
*/

int matrixChainRecursion(int arr[], int i, int j) {
    if (i == j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min( ans,
                   matrixChainRecursion(arr, i, k)
                   + matrixChainRecursion(arr, k + 1, j)
                   + arr[i - 1] * arr[k] * arr[j]
                 );
    }
    return ans;
}
//Recursion + Memoization
int matrixChainTopDown(int arr[], int i, int j, int dp[][100]) {
    if (i == j) {
        dp[i][j] = 0;
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min( ans, matrixChainTopDown(arr, i, k, dp)
                   + matrixChainTopDown(arr, k + 1, j, dp)
                   + arr[i - 1] * arr[k] * arr[j]
                 );
    }
    return dp[i][j] = ans;
}

//Bottom Up Approach
int matrixChainBottomUp(int arr[], int n) {
    int C[100][100]; //Cost
    memset(C, -1, sizeof(C));
    //Make the diagonals to 0.
    for (int i = 0; i < n; i++) {
        C[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L; i++) {
            int j = i + L - 1;
            C[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                C[i][j] = min(C[i][j] ,
                              C[i][k] + C[k + 1][j] +
                              arr[i - 1] * arr[k] * arr[j]
                             );
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {3, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << matrixChainRecursion(arr, 1, n - 1) << endl;

    int dp[100][100] = {0};
    memset(dp, -1, sizeof(dp));
    cout << matrixChainTopDown(arr, 1, n - 1, dp) << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    matrixChainBottomUp(arr, n);

    return 0;
}