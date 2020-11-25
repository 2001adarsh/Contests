#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
#define MAXN 100001

map<int, int> mp;

void factorize(int n) {

    int count = 0;
    while (!(n % 2)) {
        n /= 2;
        count++;
    }

    if (count)
        mp[2] = count;

    for (int i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            mp[i] = count;
    }
    if (n > 2)
        mp[n] = 1;
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
        mp.clear();

        factorize(n);

        int mi = 0, num = 0;
        for (auto i : mp) {
            // cout << i.first << " ";
            if (mi < i.second) {
                mi = i.second;
                num = i.first;
            }
        }

        // cout << num << " " << mi << " ";

        int prod = 1;
        cout << mi << endl;
        for (int i = 0; i < mi - 1; i++) {
            cout << num << " ";
            prod *= num;
        }
        cout << n / prod << endl;

    }

    return 0;
}