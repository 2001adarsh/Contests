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
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        int x2, y2, z2;
        cin >> x2 >> y2 >> z2;

        int sum = 0;

        //max
        int first = min(z1, y2);
        z1 -= first;
        y2 -= first;
        first *= 2;

        int second = min(z1, z2);
        z1 -= second;
        z2 -= second;

        int third = min(x1, z2);
        x1 -= third;
        z2 -= third;

        int fourth = max(z2, 0LL);
        fourth *= 2;


        sum = first - fourth;
        cout << sum << endl;

    }

    return 0;
}