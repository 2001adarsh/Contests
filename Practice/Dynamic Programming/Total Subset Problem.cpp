#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Total Subset Sum Problem:
//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/#:~:text=Subset%20Sum%20Problem%20%7C%20DP%2D25,-Last%20Updated%3A%2025&text=Given%20a%20set%20of%20non,sum%20equal%20to%20given%20sum.&text=Input%3A%20set%5B%5D%20%3D%20%7B3,%2C%205)%20with%20sum%209.

bool sendOutput(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];
    memset(dp, false, sizeof dp);

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i][j] || (dp[i - 1][j - arr[i - 1]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return dp[n][sum];
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum; cin >> sum;
    cout << sendOutput(arr, n, sum);

    return 0;
}