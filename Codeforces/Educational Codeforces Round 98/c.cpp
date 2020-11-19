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
        string str;
        cin >> str;
        stack<int> st1, st2;
        int ans = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')
                st1.push(1);
            else if (str[i] == '[')
                st2.push(1);
            else if (str[i] == ')' && (!st1.empty())) {
                if (!st1.empty()) {
                    st1.pop();
                    ans++;
                }
            } else if (str[i] == ']' && (!st2.empty())) {
                st2.pop();
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}