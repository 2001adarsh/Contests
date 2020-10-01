#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Find maximum subarray using Divide and Conquer without using Kadane's algo.

int solve(vector<int>& arr, int s, int e) {
    if (s == e)
        return arr[s];
    if (s > e)
        return 0;
    int mid = (s + e) / 2;
    int left = solve(arr, s, mid);  //getting max from left
    int right = solve(arr, mid + 1, e); //getting max from right.

    //max passing throught the centre.
    int goLeft = 0, prev = 0;
    int i = mid;
    while (i >= s) {
        prev += arr[i];
        goLeft = max(goLeft, prev);
        i--;
    }
    int goRight = 0, j = mid + 1;
    prev = 0;
    while (j <= e) {
        prev += arr[j];
        goRight = max(goRight, prev);
        j++;
    }
    // cout << goLeft << " " << goRight << endl;
    return max({left, right, goLeft + goRight});
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << solve(v, 0, n - 1) << endl;
    }

    return 0;
}