#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Check subarray with sum 0.
//longest subarray with sum 0.
int len = -1;
bool check(int n, vector<int> arr) {
    bool flag = false;

    unordered_map<int, int> mp;
    vector<int> pre(n, 0);
    pre[0] = arr[0];
    mp.insert({pre[0], 0});

    for (int i = 1; i < n; i++) {
        pre[i] += pre[i - 1] + arr[i];
        if (pre[i] == 0)
            len = max(len, i + 1);

        if (mp.count(pre[i]) > 0) {
            flag = true;
            len = max(abs(mp[pre[i]] - i), len);
        } else
            mp[pre[i]] = i;
    }
    return flag;
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
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << check(n, arr) << endl;
    cout << len;

    return 0;
}