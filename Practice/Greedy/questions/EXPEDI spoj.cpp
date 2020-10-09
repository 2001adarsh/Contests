#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.first > b.first);
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
        vector<pair<int, int> > v;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int d, f;   cin >> d >> f;
            v.push_back(make_pair(d, f));
        }
        int D, F;
        cin >> D >> F;

        sort(v.begin(), v.end(), compare);

        //Make distance from the origin
        for (int i = 0; i < n; i++)
            v[i].first = D - v[i].first;

        int x = 0, prev = 0, ans = 0;
        while (x < n) {
            if (F >= (v[x].first - prev)) {
                F -= v[x].first - prev;
                pq.push(v[x].second);
                prev = v[x].first;
                x++;
            } else {

                if (pq.empty())
                    ans = -1;
                if (ans == -1)
                    break;
                F += pq.top();
                pq.pop();
                ans ++;
            }
        }

        if (ans == -1) {
            cout << -1 << endl;
            continue;
        }
        D -= v[n - 1].first;
        if (F >= D) {
            cout << ans << endl;
            continue;
        }
        //After last position, going to last check if we have enough fuel
        while (F < D) {
            if (pq.empty())
                break;
            F += pq.top();
            pq.pop();
            ans++;
        }
        if (F < D)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}