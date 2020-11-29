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
        int x, y, n;
        cin >> x >> y >> n;
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if ( (x ^ i) < (y ^ i) ) {
                // cout << i << " ";
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}