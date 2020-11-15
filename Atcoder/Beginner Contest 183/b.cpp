#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double ans = 0;
    int x = (d * a) + (b * c);
    int y = b + d;
    ans = (double)x / (double)y;
    cout << fixed << setprecision(10) << ans;

    return 0;
}