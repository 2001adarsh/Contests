#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// http://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
// Ropes Binary Search

bool isGood(int arr[], int n, int k, double x) {
    int cuts = 0;
    for (int i = 0; i < n; i++)
        cuts += (arr[i] / x);
    if (cuts >= k)
        return true;
    return false;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    double res = -1;
    double l = 0.00, r = 10000000.00;
    for (int i = 0; i < 100; i++) {
        double mid = (r - l) / 2 + l;
        if (isGood(arr, n, k, mid))
            res = mid, l = mid;
        else r = mid;
    }

    cout << setprecision(6) << fixed << res;


    return 0;
}