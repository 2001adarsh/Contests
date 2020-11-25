#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int getResult(int arr[], int n, int val) {
    int ans = 0, cnt = 0, lastInd = -1;

    if (arr[0] != val)
        ans++;
    else {
        cnt = 1;
        lastInd = 0;
    }


    for (int i = 1; i < n; i++) {
        if (arr[i] == val && cnt == 0) {
            lastInd = i;
            cnt++;
        } else if (arr[i] == val) {
            if ( i - lastInd > 1)
                ans++;
            lastInd = i;
        }
    }
    if (arr[n - 1] != val)
        ans++;

    return ans;
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
        int arr[n + 1];
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int small = 0, sm = INT_MAX;
        for (auto i : mp) {
            if (sm > i.second) {
                small = i.first;
                sm = i.second;
            }
        }
        // cout << small << " ";
        int left = getResult(arr, n, arr[0]);
        int right = getResult(arr, n, arr[n - 1]);
        int smallest = getResult(arr, n, small);
        // cout << left << " " << right << " " << smallest << " ";
        cout << min({left, right, smallest}) << endl;

    }

    return 0;
}