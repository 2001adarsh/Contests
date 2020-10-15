#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Maximum Subarray: Kadan's Algorithm.
//O(N)
//create a dp to have max till that point. and Max_so_far for global max till now.
int maxSum(int arr[], int n) {
    int dp[1000];
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    int max_so_far = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0) {
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

//space optimised algo.
int spaceOpti(int arr[], int n) {
    int sum = 0;
    int max_so_far = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) sum = 0;
        max_so_far = max(max_so_far, sum);
    }
    return max_so_far;
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
    cout << maxSum(arr, n);
    cout << spaceOpti(arr, n);

    //One special case -> when all elements are negative then,
    //the ans returned would be 0. so if 0, return the maximum element
    // of the array.

    return 0;
}