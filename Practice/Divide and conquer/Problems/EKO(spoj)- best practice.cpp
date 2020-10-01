#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

//EKO spoj

int solve(int *arr, int n, int cut) {
    int wood = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > cut)
            wood += (arr[i] - cut);
    }
    return wood;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, K, mx = INT_MIN;
    cin >> n >> K;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    //search space
    int s = 0, e = mx, ans = 0;

    while (s <= e) {
        int mid = (s + e) / 2;
        int wood = solve(arr, n, mid);
        //cout << s << " " << e << " " << mid << " " << wood << endl;
        if (wood >= K) { //Valid, now search for min.
            ans = mid;
            s = mid + 1;
        } else
            e = mid - 1;
    }
    cout << ans;

    return 0;
}