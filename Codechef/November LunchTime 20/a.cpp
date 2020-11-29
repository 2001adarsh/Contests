#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += arr[i];
            if (i + 1 > ans)
                break;
        }
        cout << ans << endl;
    }

    return 0;
}