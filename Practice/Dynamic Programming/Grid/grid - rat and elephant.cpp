#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Rat approach -> single step (either right or down.)
/*
    No. of ways to reach the last point (R-1, C-1) in the grid.
    Grid Based DP.
*/

int n;
int recursive_rat(int x, int y) { //memoize it with 2D dp.
    if (x < 0 or y < 0)
        return 0;
    if (x == 0 or y == 0)
        return 1;
    return recursive_rat(x - 1, y) + recursive_rat(x, y - 1);
}
void reach() {
    int dp[n][n];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1; //both in first row and in first col. there is only one way to reach, as moves are right and down only.
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
//Hint: If there is a blocked way then mark it as 0 in case of ways. or INT_MAX if finding shortest path.


//Elephant approach -> k steps chess like (either right or down.)
/*
    2D version of Ladder Problem.
    No. of ways to reach the last point (R-1, C-1) in the grid.
    Grid Based DP.
*/
void elephant() {
    int dp[n][n];
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //fill the dp
            dp[i][j] = 0;
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else {
                // dp will contain the sum of all element in row, and in coloumn.
                for (int k = 0; k < i; k++)
                    dp[i][j] += dp[k][j];
                for (int k = 0; k < j; k++)
                    dp[i][j] += dp[i][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

// Efficient Elephant approach.
// using prefix arrays for summation.
void elephant_efficient() {
    int dp[n][n];
    memset(dp, 0 , sizeof dp);

    int row[n][n];
    memset(row, 0, sizeof row);
    row[0][0] = 0; //row wise prefix sum.

    int col[n][n];
    memset(col, 0, sizeof col);
    col[0][0] = 0; //column wise prefix sum.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else {
                if (j > 0)
                    row[i][j] = row[i][j - 1] + dp[i][j - 1];
                if (i > 0)
                    col[i][j] = col[i - 1][j] + dp[i - 1][j];

                dp[i][j] = row[i][j] + col[i][j];
            }
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
    //rat
    cin >> n;
    reach();

    cout << "\n";
    cout << recursive_rat(3, 3) << endl;

    //elephant
    elephant();

    //elephant efficient
    cout << endl;
    elephant_efficient();

    return 0;
}