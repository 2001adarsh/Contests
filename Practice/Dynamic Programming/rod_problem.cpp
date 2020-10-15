#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Rod Cutting problem. given total length of rod, cut each rod with definite
//amount to get max price.

int topDown(int N, int length[], int price[], int k, int dp[]) {
    if (N < 0)
        return INT_MIN;
    if (N == 0)
        return 0;
    if (dp[N] != 0)
        return dp[N];
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (length[i] <= N)
            ans = max(ans, (price[i] + topDown(N - length[i], length, price, k, dp)));
    }
    return dp[N] = ans;
}

//Bottom Up DP
int bottomUp(int length[], int price[], int k, int N) {
    int dp[1000] = {0};
    for (int i = 1; i <= N; i++) {
        int get = INT_MIN;
        for (int j = 0; j < k; j++) {
            if (length[j] <= i)
                get = max(get, price[j] + dp[i - length[j]]);
        }
        dp[i] = get;
    }

    return dp[N];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    int k;
    cin >> k;
    int length[k], price[k];
    for (int i = 0; i < k; i++)
        cin >> length[i] >> price[i];
    int dp[1000] = {0};
    cout << topDown(N, length, price, k, dp);
    cout << endl << bottomUp(length, price, k, N);
    return 0;
}