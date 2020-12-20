#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.youtube.com/watch?v=Uz0WD9yRzFE
// Multi-Dimensional DP
// Alyona and String - Codeforces.
// https://codeforces.com/contest/682/problem/D

int dp[1005][1005][12][2];

int solve(string& a, string& b, int i, int j, int rem, int cont) {
    if (i == a.size() || j == b.size())
        return (rem == 0) ? 0 : INT_MIN; //cautious

    if (rem == 0)
        return 0;

    if (dp[i][j][rem][cont] != -1)
        return dp[i][j][rem][cont];


    /*
        //lengthy to understand better - >
        if (cont) { // if the substring is in continuity.
            return dp[i][j][rem][cont] = max({
                solve(a, b, i + 1, j, rem - 1, 0),
                solve(a, b, i, j + 1, rem - 1, 0),
                (a[i] == b[j]) ? (1 + solve(a, b, i + 1, j + 1, rem, 1)) : 0 ,
                (a[i] == b[j]) ? (1 + solve(a, b, i + 1, j + 1, rem - 1, 0)) : 0
            });
        } else { //either start a new substring or leave these
            return dp[i][j][rem][cont] = max({
                solve(a, b, i + 1, j, rem, 0),
                solve(a, b, i, j + 1, rem, 0),
                (a[i] == b[j]) ? (1 + solve(a, b, i + 1, j + 1, rem, 1)) : 0, //got 1 lenght of substring,if true.
                (a[i] == b[j]) ? (1 + solve(a, b, i + 1, j + 1, rem - 1, 0)) : 0
            });
        }
    */
    //code could be shrinked as,
    int ans = 0;
    ans = max(ans, solve(a, b, i + 1, j, rem - cont, 0));
    ans = max(ans, solve(a, b, i, j + 1, rem - cont, 0));
    if (a[i] == b[j]) {
        ans = max(ans, 1 + solve(a, b, i + 1, j + 1, rem, 1));
        ans = max(ans, 1 + solve(a, b, i + 1, j + 1, rem - 1, 0));
    }
    return dp[i][j][rem][cont] = ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << solve(a, b, 0, 0, k, 0);

    return 0;
}