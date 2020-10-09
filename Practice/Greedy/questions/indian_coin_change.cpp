#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Greedy algorithm, works well for the Indian Currency, in the coin change problem

int numberOfCoins(int *coins, int n, int money) {
    int ans = 0;
    while (money) {
        int idx = upper_bound(coins, coins + n, money) - coins - 1;
        money -= coins[idx];
        ans++;
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
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);
    cout << numberOfCoins(coins, t, n);


    return 0;
}