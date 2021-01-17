#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Number of Palindromic Substring
// https://leetcode.com/problems/palindromic-substrings/

const int N = 105;
int isPalin[N][N];

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    int n = str.size();


    memset(isPalin, 0, sizeof isPalin);

    //pre computation of palindrome for different positions.
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            if (i == j)
                isPalin[i][j] = 1;
            else if (str[i] == str[j] && j - i == 1)
                isPalin[i][j] = 1;
            else if (str[i] == str[j] && i < j and  isPalin[i + 1][j - 1])
                isPalin[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) {
            if (isPalin[i][j])
                ans++;
        }
    }

    cout << ans;
    return 0;
}