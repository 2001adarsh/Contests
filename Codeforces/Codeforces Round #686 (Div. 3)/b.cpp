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
        map<int, int> mp;
        int arr[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int mi = -1;

        for (auto i : mp) {
            if (i.second == 1) {
                mi = i.first;
                break;
            }
        }

        if (mi == -1) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == mi) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}