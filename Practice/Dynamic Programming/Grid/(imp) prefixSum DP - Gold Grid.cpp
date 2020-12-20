#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

/*
Gold Grid
an N∗N grid. Each square in the grid either has or does not have a gold coin. He has to divide the gamefield with his three other friends as follows: he will draw one horizontal line and one vertical line to divide the field into four rectangles. His friends will choose three of the four smaller fields and he gets the last one.

He wants to divide the field so that he gets the maximum number of goldcoins, assuming that his friends will pick the best three rectangles.
*/

int n, m;
int dp[1000][1000]; //Prefix of 2D array.
int board[1000][1000];

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 0;
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    //printing board
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    ///Creating a prefix Sum 2D array.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                dp[i][j] = board[i][j];
            else if (i == 1)
                dp[i][j] = dp[i][j - 1] + board[i][j];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j] + board[i][j];
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
            }
        }
    }
    //Printing PreFix Sum of 2D board containing 0 & 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    int ans = 0;
    //For each x,y creating 4 squares and finding max(min(squares having gold))
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //cutting board at each i,j
            int sq1 = dp[i][j];
            int sq2 = dp[i][n] - dp[i][j];
            int sq3 = dp[n][j] - dp[i][j];
            int sq4 = dp[n][n] - dp[i][n] - dp[n][j] + dp[i][j];

            ans = max ( min(sq1, min(sq2, min(sq3, sq4))), ans);
        }
    }
    cout << ans;

    return 0;
}