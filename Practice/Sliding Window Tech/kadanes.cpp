#include<bits/stdc++.h>
using namespace std;
#define int long long int

//Kadane's Algorithm

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(int);
    int mx = arr[0], ans = arr[0];

    for (int i = 1; i < n; i++) {
        mx = max(mx + arr[i], arr[i]);
        ans = max(mx, ans);
    }
    cout << ans;

    /*
    Here we are using greedy way to find the maximum subarray till the
    array from the starting. And then finding maximum value of all max
    subarray found for each points.
    */

    return 0;
}