#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/maximum-sum-pairs-specific-difference/

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int k;
        cin >> k;
        sort(arr, arr + n);
        int dp[n] = {0}, ans = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] < k) {
                dp[i] = arr[i] + arr[i - 1] + ((i - 2 >= 0 ) ? dp[i - 2] : 0);
            } else
                dp[i] = dp[i - 1];
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}