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

void minCoins(int arr[], int n) {
    int dp[10000] = {0};
    for (int i = 1; i <= W; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i - arr[j]], dp[i]);
            }
        }
        dp[i] += 1;
    }
    return dp[W];
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
    minCoins(arr, n);
    return 0;
}