#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> nums;
const int N = 1e3;
int dp[N][N];

int maxCoins(int start, int end) {
    if (start + 1 > end - 1)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];

    int max_coins = 0;
    for (int i = start + 1; i < end; i++) {
        int burstThis = nums[start] * nums[i] * nums[end];
        burstThis += maxCoins(start, i) + maxCoins(i, end);

        max_coins = max(max_coins, burstThis);
    }
    return dp[start][end] = max_coins;
}


int32_t main()
{

    int n;
    cin >> n;
    nums.resize(n + 2);
    memset(dp, -1, sizeof dp);

    nums[0] = 1;
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    nums[n + 1] = 1;

    cout << maxCoins(0, n + 1);

    return 0;
}