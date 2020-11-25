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
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;

        while (q--) {
            int l, r;
            cin >> l >> r;
            char left = str[l - 1];
            char right = str[r - 1];
            // cout << left << " " << right << " ";
            bool flag = false;
            for (int i = l - 2; i >= 0; i--) {
                if (left == str[i]) {
                    // cout << i << " ";
                    flag = true;
                }
            }
            for (int i = r; i < n; i++) {
                if (right == str[i]) {
                    // cout << i << " ";
                    flag = true;
                }
            }

            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}