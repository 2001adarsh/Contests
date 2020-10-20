#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//C- Vacations https://atcoder.jp/contests/dp/tasks/dp_c

vector<vector<int>> arr;
int n;
int dp[200005][3];

//recursive - failing 2 testcases.
int funct(int N, int i) {
    if (N == 0)
        return 0;
    if (dp[N - 1][i] != -1)
        return dp[N - 1][i];
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        if (j != i)
            ans = max(ans, arr[N - 1][j] + funct(N - 1, j));
    }
    return dp[N - 1][i] = ans;
}

//Bottom Up Approach. Passed all testcases.
int bottomUp(int N) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr.push_back({x, y, z});
    }
    cout << bottomUp(n);
    // memset(dp, -1, sizeof dp);
    // cout << funct(n, -1);

    return 0;
}