#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
/*
two cases.
The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions. So, count = k * S(n-1, k)
The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition ( single element partition).So, count = S(n-1, k-1)
*/
int recursive(int n, int k) {
    if (n == k || k == 1)
        return 1;
    if (k > n)
        return 0;
    return k * recursive(n - 1, k) + recursive(n - 1, k - 1);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    int dp[100][100];
    cout << recursive(n, k) << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {

            if (j == 1)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = 0;
            else
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}