#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


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
        if (n == 1) {
            cout << 0 << endl;
        } else if (n == 2)
            cout << 1 << endl;
        else if (n == 3)
            cout << 2 << endl;
        else if (n % 2 == 0) {
            cout << 2 << endl;
        } else
            cout << 3 << endl;

    }
    return 0;
}