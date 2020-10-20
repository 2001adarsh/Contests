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

    int t, p = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << p << ": ";
        p++;
        string s;
        cin >> s;
        if (s.size() < 9) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0, cnt = 0;
        vector<int> kick;
        for (int i = 0; i < s.size() - 4; i++) {
            if (s[i] == 'K') {
                if (s[i + 1] == 'I' && s[i + 2] == 'C' && s[i + 3] == 'K') {
                    kick.push_back(1);
                }
            } else if (s[i] == 'S') {
                if (s[i + 1] == 'T' && s[i + 2] == 'A' && s[i + 3] == 'R' && s[i + 4] == 'T') {
                    kick.push_back(0);
                    cnt++;
                }
            }
        }
        for (int i = 0; i < kick.size(); i++) {
            if (kick[i] == 0)
                cnt--;
            else
                ans += cnt;
        }
        cout << ans << endl;
    }

    return 0;
}