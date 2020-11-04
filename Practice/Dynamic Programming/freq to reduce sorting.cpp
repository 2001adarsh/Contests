#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// Jon Snow and his Favourite Number
// https://codeforces.com/problemset/problem/768/C
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> freq(10005, 0);
    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        freq[in]++;
    }
    while (k) {
        int odds = 0;
        vector<int> temp(10005, 0);
        for (int i = 0; i < 10005; i++) {
            if (freq[i] == 0)
                continue;
            if (freq[i] % 2 == 0) {
                temp[i] += freq[i] / 2;
                temp[(i ^ x)] += freq[i] / 2;
                continue;
            }
            odds++;
            if (odds & 1) { //ceil
                int going = ceil( (double)freq[i] / (double) 2);
                temp[i] += freq[i] - going;
                temp[(i ^ x)] += going;
            } else {
                int going = floor((double)freq[i] / (double) 2);
                temp[i] += freq[i] - going;
                temp[(i ^ x)] += going;
            }
        }
        freq = temp;
        temp.clear();
        k--;
    }

    int mi = INT_MAX, ma = INT_MIN;
    for (int i = 0; i < 10005; i++) {
        if (freq[i] != 0) {
            if (mi == INT_MAX)
                mi = i;
            ma = i;
        }
    }
    cout << ma << " " << mi;
    return 0;
}