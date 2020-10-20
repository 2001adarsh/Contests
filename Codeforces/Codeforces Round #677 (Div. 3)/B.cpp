#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

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
        int arr[n], ones = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i]) ones++;
        }
        vector<pair<int, int>> p;
        bool flag = false;
        int s = -1, e = -1;
        for (int i = 0 ; i < n; i++) {
            if (arr[i] == 0 && flag == false) {
                s = -1, e = -1;
            } else if (arr[i] == 0) {
                p.push_back({s, e});
                s = -1, e = -1;
                flag = false;
            }
            else if (arr[i] == 1 && flag == false) {
                s = i;
                e = i;
                flag = true;
            } else if (arr[i] == 1) {
                e = i;
            }
        }
        if (arr[n - 1] == 1)
            p.push_back({s, n - 1});
        int gap = 0;
        for (int i = 1; i < p.size(); i++) {
            gap += p[i].first - p[i - 1].second - 1;
        }
        cout << gap << endl;
    }

    return 0;
}