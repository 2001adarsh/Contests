#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Finding closest squareroot of a number: N using binary search.
//Search space - [0 to N]

float squareroot(int n) {
    int s = 0, e = n;
    float ans = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        int sm = mid * mid;
        if (sm == n)
            return mid;
        else if (sm > n)
            e = mid - 1;
        else {
            ans = mid;
            s = mid + 1;
        }
    }

    //for float precision
    float inc = 0.1;
    int p = 3;
    for (int i = 0; i < p; ++i)
    {
        while (ans * ans < n) {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }
    return ans;
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
    cout << squareroot(n);

    return 0;
}