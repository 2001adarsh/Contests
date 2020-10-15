#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// Platforms -> https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%208/798_English.htm
/*
one platform to the neighboring, he spends |y2 – y1| energy, where y1 and y2 are the heights where these platforms hang. The hero can make a super jump that allows him to skip one platform, but it takes him 3 * | y3 – y1| energy.

You are given the heights of the platforms in order from the left side to the right. Find the minimum amount of energy to get from the 1-st (start) platform to the n-th (last). Print the list (sequence) of the platforms that the hero must pass.
*/

int dp[100000];
int parent[100000];
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    parent[0] = 0;
    memset(parent , -1, sizeof parent);
    memset(dp, -1, sizeof dp);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        if (i == 1) {
            dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
            parent[i] = i - 1;
        } else {
            int x = dp[i - 1] + abs(arr[i] - arr[i - 1]);
            int y = dp[i - 2] + 3 * abs(arr[i] - arr[i - 2]);
            if (x <= y) {
                dp[i] = x;
                parent[i] = i - 1;
            } else {
                dp[i] = y;
                parent[i] = i - 2;
            }
        }
    }
    cout << dp[n - 1] << endl;

    vector<int> par;
    int i = n - 1;
    par.push_back(i + 1);
    while (i != 0) {
        i = parent[i];
        par.push_back(i + 1);
    }

    cout << par.size() << endl;
    for (int i = par.size() - 1; i >= 0; i--)
        cout << par[i] << " ";
    return 0;
}