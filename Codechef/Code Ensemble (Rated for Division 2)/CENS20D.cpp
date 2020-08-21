#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

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
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v.push_back(x);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] == (v[i]&v[j]) ) {
                    //cout << i << " " << j << endl;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}