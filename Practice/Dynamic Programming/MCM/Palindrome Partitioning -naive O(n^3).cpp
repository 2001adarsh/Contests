#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Palindrome Partitioning

int dp[1000][1000];

int palindrome(string str, int i, int j) {
    if ( i >= j )
        return 0;

    //check if already a palindrome.
    int x = i, y = j; bool flag = true;
    while (x <= y) {
        if (str[x] != str[y]) {
            flag = false;
            break;
        }
        x++, y--;
    }
    if (flag) return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = palindrome(str, i, k) + 1 + palindrome(str, k + 1, j);
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    memset(dp, -1, sizeof dp);
    string str; cin >> str;
    cout << palindrome(str, 0, str.size() - 1);

    return 0;
}