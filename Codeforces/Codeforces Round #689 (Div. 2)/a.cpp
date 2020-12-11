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
        int n, k;
        cin >> n >> k;
        string str = "";
        for (int i = 0; i < k; i++) {
            str += 'a';
        }
        int p = 1;
        for (int j = k; j < n; j++) {
            str += (char)(p % 3 + 97);
            p++;
        }
        cout << str << endl;
    }

    return 0;
}