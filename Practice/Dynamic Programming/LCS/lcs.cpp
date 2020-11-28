#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//LCS -> Longest Common Subsequence between two strings.

//return string
string lcs_string( string X, string Y, int m, int n )
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    string str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str.insert(0, 1, X[i - 1]);
            i--; j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    return str;
}


//Recursion + Memoization
int lcs(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
    if (i >= s1.size() || j >= s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
    int op1 = lcs(s1, s2, i + 1, j, dp);
    int op2 = lcs(s1, s2, i, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}


//Recursive Approach
int lcs_recusion(string s1, string s2, int i, int j) {
    if (i >= s1.size() || j >= s2.size())
        return 0;
    if (s1[i] == s2[j])
        return 1 + lcs_recusion(s1, s2, i + 1, j + 1);
    int left = lcs_recusion(s1, s2, i + 1, j);
    int right = lcs_recusion(s1, s2, i, j + 1);
    return max(left, right);
}
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    cout << lcs_string(s1, s2, s1.size(), s2.size()) << endl;
    cout << lcs(s1, s2, 0, 0, dp);
    return 0;
}

//Brute Force method:
/*
    Find all the subsequence of smaller string, and check if it is present in
    the larger string. If yes, then check for maximum length.
    Time complexity - O(n*2^n)
    O(n) to check if it is present in larger string
    O(2^n) to produce all the substring.
*/