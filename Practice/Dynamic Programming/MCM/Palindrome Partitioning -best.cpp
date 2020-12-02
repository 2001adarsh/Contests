#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e9

/*
    Instead of calculating the palindromes at the time of calculating partitionings,
    we cant already keep the palindrome status precomputed in o(n^2).
    and then club it with the partitioning o(n^2). making
    overall time complexity to be o(N^2) only.
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    int n = str.size();

    //Calculating the palindrome early.
    bool P[n + 1][n + 1];
    memset(P, false, sizeof P);

    for (int i = 0; i < n; i++) //size 1 will always be palindrome.
        P[i][i] = true;

    for (int gap = 1; gap < n - 1; gap++) {
        for (int i = 0; i < n - gap + 1; i++) {
            int j = i + gap;
            if (gap == 1) {
                if (str[i] == str[j]) P[i][j] = true;
                else continue;
            }
            else if (str[i] == str[j] && P[i + 1][j - 1] == true)
                P[i][j] = true;
        }
    }

    //checking out Palindrome identifier table.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    /*
        Can do this thing, but still it will lead to O(N^3) solution.


        // Look up table for calculating, partitioning.
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);

        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (P[i][j] == true)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = inf;
                    for (int k = i; k < j; k++)
                        dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }

        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << dp[0][n - 1];
    */

    // So inorder to convert the solution to O(N^2),
    // We can check for the prefix of the array, if it is palindrome, we can get the partitions
    // from the left part.
    // https://www.youtube.com/watch?v=qmTtAbOTqcg

    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++) {
        if (P[0][i]) dp[i] = 0;
        else {
            dp[i] = inf;
            for (int j = 0; j < i; j++) {
                if (P[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n - 1];

    return 0;
}