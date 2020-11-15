#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// https://www.codechef.com/problems/COINS
// use of MAP in DP.
/*
This is true inspite of having N = 10^9, because for each case, we are
just going for logn values, and there is need for storing these logn
values only.

Remember - When constraints are big, but states are less. Use Map.
*/

map<int, int> mp;
int fun(int n) {
    if (n <= 0)
        return 0;
    if (mp.count(n) > 0)
        return mp[n];
    //three options
    int op1 = fun(n / 2);
    int op2 = fun(n / 3);
    int op3 = fun(n / 4);

    int max_weight = max(op1 + op2 + op3, n);
    return mp[n] = max_weight;
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

    cout << fun(n);

    return 0;
}