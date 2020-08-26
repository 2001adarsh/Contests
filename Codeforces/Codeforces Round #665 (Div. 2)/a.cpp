#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

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
        int n, k;
        cin >> n >> k;
        if (n == k)
            cout << 0 << endl;
        else if (k > n)
            cout << k - n << endl;
        else {
            int x = n - k;
            if (x % 2 == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }


    return 0;
}