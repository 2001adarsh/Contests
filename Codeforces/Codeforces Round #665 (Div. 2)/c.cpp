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
        int n;
        cin >> n;
        vector<int> v(n), sorted(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sorted[i] = v[i];
        }
        sort(sorted.begin(), sorted.end());

        if (is_sorted(v.begin(), v.end())) {
            cout << "YES" << endl;
            continue;
        }
        else {
            bool flag = false;
            int mi = *min_element(v.begin(), v.end());
            for (int i = 0; i < n; i++) {
                if (sorted[i] != v[i]) {
                    if (v[i] % mi != 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}