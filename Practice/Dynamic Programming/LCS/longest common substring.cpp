#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    int board[n + 1][m + 1];
    memset(board, 0, sizeof board);
    int ans = 0, posi, posj;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1])
                board[i][j] = board[i - 1][j - 1] + 1;

            if (ans < board[i][j]) {
                ans = board[i][j];
                posj = j, posi = i;
            }
        }
    }
    cout << ans;

    //finding the Longest common substring.
    string res = "";

    while (posi >= 0 && posj >= 0) {
        if (s1[posi - 1] == s2[posj - 1]) {
            res = s1[posi - 1] + res;
            posi--, posj--;
        } else
            break;
    }
    cout << res;

    return 0;
}