#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Knapsack 1 https://atcoder.jp/contests/dp/tasks/dp_d

vector<pair<int, int>> bag;
int N;
int dp[100005][100];

int topDown(int W, int i) {
    if (W < 0)
        return INT_MIN;
    if (W == 0 || i == N)
        return 0;
    if (dp[W][i] != 0)
        return dp[W][i];

    int take = bag[i].second + topDown(W - bag[i].first , i + 1);
    int leave = topDown(W, i + 1);

    return  dp[W][i] = max(take, leave);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, W;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int w, v; cin >> w >> v;
        bag.push_back({w, v});
    }
    memset(dp, 0, sizeof dp);
    cout << topDown(W, 0);

    return 0;
}

//Bottom UP
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

struct item
{
    int val;
    int wt;
};

int solve(vector<item> arr, int N, int W) {
    int dp[N + 1][W + 1];
    for (int w = 0; w <= W; w++)
        dp[1][w] = 0;
    dp[1][arr[1].wt] = arr[1].val;

    for (int i = 2; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (arr[i].wt > w)
                continue;
            dp[i][w] = max(dp[i][w], arr[i].val + dp[i - 1][w - arr[i].wt]);
        }
    }

    return *max_element(dp[N] , dp[N] + W + 1);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, W;
    cin >> n >> W;
    vector<item> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].wt >> arr[i].val;
    }

    cout << solve(arr, n, W);


    return 0;
}
*/