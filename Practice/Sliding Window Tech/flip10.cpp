#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray of 1s.

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (k == 0) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i]) cnt++;
            else cnt = 0;
            ans = max(cnt, ans);
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        return 0;
    }
    int beg = -1, en = -1;
    int start = 0, ans = 0;
    for (int end = 0; end < n; end++) {
        if (arr[end] == 0) {
            if (k) {
                k--;
            } else {
                //move start forward, till k becomes atleast 1.
                while (k == 0 && start < n) {
                    if (arr[start] == 0)
                        k++;
                    start++;
                }
                k--;
            }
        }

        if (ans < end - start + 1) {
            ans = end - start + 1;
            beg = start;
            en = end;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (i >= beg && i <= en)
            cout << "1 ";
        else
            cout << arr[i] << " ";
    }
    return 0;
}