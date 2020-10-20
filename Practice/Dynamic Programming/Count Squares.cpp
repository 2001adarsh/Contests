#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
//Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    //printing the prefix sum array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    int count = dp[m][n];

    for (int sub = 2; sub <= min(m, n); sub++) {
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i >= sub && j >= sub) {
                    int x = dp[i][j] - dp[i - sub][j] - dp[i][j - sub] + dp[i - sub][j - sub];
                    if (x >= sub * sub) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
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
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << countSquares(mat);

    return 0;
}