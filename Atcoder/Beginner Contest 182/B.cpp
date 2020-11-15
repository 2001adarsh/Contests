#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

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

    int ans = 0, ele = 2;

    for (int i = 2; i <= 1000; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] % i == 0)
                res++;
        }
        // cout << res << " ";
        if (res > ans) {
            ans = res;
            ele = i;
        }
    }
    cout << ele;
    return 0;
}