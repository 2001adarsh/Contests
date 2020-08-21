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
        string s;
        cin >> s;
        int l, r;
        cin >> l >> r;
        int R = 0, L = 0, U = 0, D = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R')
                R++;
            else if (s[i] == 'L')
                L++;
            else if (s[i] == 'U')
                U++;
            else
                D++;
        }
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            int dx = x - l, dy = y - r;
            int cnt = 0, flag = true;

            if (dx > 0) {
                if (R >= dx)
                    cnt += dx;
                else flag = false;
            } else if (dx < 0) {
                dx = -dx;
                if (L >= dx)
                    cnt += dx;
                else flag = false;
            }

            if (dy > 0) {
                if (U >= dy)
                    cnt += dy;
                else flag = false;
            } else if (dy < 0) {
                dy = -dy;
                if (D >= dy )
                    cnt += dy;
                else flag = false;
            }

            if (flag) {
                cout << "YES" << " " << cnt << endl;
            } else
                cout << "NO" << endl;
        }

    }

    return 0;
}