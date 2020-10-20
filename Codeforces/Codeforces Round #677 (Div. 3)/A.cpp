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
        string n;
        cin >> n;
        int f = n[0] - '0';
        // cout << f << " ";
        int calls = (f - 1) * 10;
        int s = n.size();
        calls += (s * (s + 1)) / 2;
        cout << calls << endl;
    }

    return 0;
}