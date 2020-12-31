#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e9

// Better ans of LIS - Longest Increasing Subsequence
// This solution is only to find the Length of LIS and not the LIS itself

/*
 dp[len] -> the 'element i' at which the subsequence of 'length len' ends.

    hence, we have to find the 'position len' where,
    dp[len] < arr[i] < dp[len+1]

 observation ->
    - if there is a higher value at dp[len] and there is a smaller afterwards,
      we replace with the smaller value
    - this is done so as to add more future elements in the subsequence.
*/

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
    int dp[n + 1]; //one extra length, considering 0th len also.

    //initialisation of dp array. such that, 1st element will always lie between -inf to inf.
    dp[0] = -inf;
    for (int i = 1; i <= n; i++)
        dp[i] = inf;

    //progress.
    for (int i = 0; i < n; i++) {
        int element = arr[i];
        //check for the len of dp's where it can be allocated.
        //strictly increasing.
        for (int len = 0; len < n; len++) {
            if (dp[len] < element and element < dp[len + 1]) { //this is the right place.
                dp[len + 1] = element;
                break;
            }
        }
    }

    int maxLength = 0; //LIS
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
        if (dp[i] != inf)
            maxLength = i;
    }

    cout << maxLength;

    return 0;
}