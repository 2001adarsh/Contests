#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//BusyMan SPOJ
//Activity Selection, the best way is to sort according to the end time of the
//activities. this way it works perfect.

bool const comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second)
        return true;
    return false;
}

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
        vector<pair<int, int> > vec;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            vec.push_back({x, y});
        }

        sort(vec.begin(), vec.end(), comp);
        int ans = 1;
        int l = vec[0].first, r = vec[0].second;
        for (int i = 1; i < n; i++) {
            if (vec[i].first >= r) {
                ans++;
                l = vec[i].first, r = vec[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}