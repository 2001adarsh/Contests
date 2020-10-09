#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

/*
There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.
First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).
4
1 1
2 1
3 1
4 1
*/

bool comp(pair<int, int>A, pair<int, int> B) {
    return A.second < B.second;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x - y, x + y));
    }
    sort(v.begin(), v.end(), comp);
    int prev = v[0].second, cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].first > prev) {
            prev = v[i].second;
        } else
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}