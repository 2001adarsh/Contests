#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int MAX = 100;

// Gold mine Problem -https://www.geeksforgeeks.org/gold-mine-problem/

int getMaxGold(int arr[100][100], int m, int n) {
    int dp[100][100];
    memset(dp, -1, sizeof dp);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (j == 0)
                dp[i][j] = arr[i][j];
            else {
                dp[i][j] = dp[i][j - 1]; //right
                if (i != 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]); //right-down
                if (i != m - 1)
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]); //right-up
                dp[i][j] += arr[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 1; //return maximum in the last column
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int gold[MAX][MAX] = {  {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);

    return 0;
}