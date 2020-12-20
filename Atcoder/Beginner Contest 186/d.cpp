#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    int arr[n + 1];

    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        ans += arr[i] * (i);
        ans -= arr[i] * (n - i - 1);
        // cout << ans << endl;
    }
    cout << ans;
    return 0;
}