#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Longest Increasing Subsequence
// Standard Solution - O(N^2)

// For every point, check for a best valid subsequence previously found and 1 to it.

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

    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    int parent[n + 1];
    memset(parent, -1, sizeof parent);

    int ans = 0, endPoint = 0;

    for (int i = 1; i < n; i++) {
        int j = i;
        j--;
        while (j >= 0) {
            if (arr[j] < arr[i] && dp[i] < 1 + dp[j]) { //validity
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
            j--;
        }

        if (ans < dp[i]) {
            ans = dp[i];
            endPoint = i;
        }
    }
    //Length of subsequence
    cout << ans << endl;

    //Printing Subsequence -> reverse order.
    while (parent[endPoint] != -1) {
        cout << arr[endPoint] << " ";
        endPoint = parent[endPoint];
    }
    cout << arr[endPoint];

    return 0;
}

/*
8
1 5 2 3 4 9 6 10
*/

