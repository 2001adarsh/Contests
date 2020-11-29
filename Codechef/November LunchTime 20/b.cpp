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
        int f[n], c[n];
        for (int i = 0; i < n; i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        // priority_queue<int, vector<int>, greater<int>> q;

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            if (f[i] != 0)
                vec.push_back({c[i], f[i]});
        }

        sort(vec.begin(), vec.end());
        int k = 0, ans = 0;
        for (int i = 0; i < n; ) {
            if (vec[k].second != 0) {
                ans += vec[k].first;
                vec[k].second--;
            } else {
                k++;
                continue;
            }
            i++;
        }
        cout << ans << endl;

    }

    return 0;
}