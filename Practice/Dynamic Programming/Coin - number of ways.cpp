#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

const int N = 1005;
int arr[N];
int W;
int dp[N][N];

void numberOfWays(int n) {
    for (int i = 0; i < n; i++) //1 way, donot select any.
        dp[i][0] = 1;

    for (int i = 1; i <= W; i++) { //1st row, for coin[0].
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            if (arr[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i]];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << "The total number of ways are: " << dp[n - 1][W] << endl;
}

void minCoins(int n, int coins[]) {
    int dp1[100][100];
    memset(dp1, 0, sizeof dp1);

    for (int i = 1; i <= W; i++) {
        if (i % coins[0] == 0)
            dp1[0][i] = 1 + dp1[0][i - coins[0]];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < coins[i])
                dp1[i][j] = dp1[i - 1][j];
            else
                dp1[i][j] = min(dp1[i - 1][j] , 1 + dp1[i][j - coins[i]]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++)
            cout << dp1[i][j] << " ";
        cout << endl;
    }
    cout << "The min number of coins required are: " << dp1[n - 1][W];
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> W;

    numberOfWays(n);
    // minCoins(n, arr);
    return 0;
}