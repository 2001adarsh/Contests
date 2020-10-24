#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

const int N = 3005;
int dp[N][N];
int arr[N];

int funct(int i, int j) {
    if (i == j)
        return arr[i];
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    //as opponent will play optimally and will leave the min for you.
    int op1 = arr[i] + min(funct(i + 1, j - 1), funct(i + 2, j));
    int op2 = arr[j] + min(funct(i, j - 2), funct(i + 1, j - 1));
    return dp[i][j] = max(op1, op2);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    memset(dp, -1, sizeof dp);
    int fr = funct(0, n - 1);
    int sec = total - fr;
    cout << fr - sec;

    return 0;
}