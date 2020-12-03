#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Recursive way, to understand Boolean Parenthesization Problem.
//https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

//This code can be easily converted into Dp, by using memoization
// dp[str.size()][str.size()][2]

int ways(string str, int i, int j, bool req) {
    if (i == j) {
        if (str[i] == 'T' && req == true) return 1;
        else if (str[i] == 'F' && req == false) return 1;
        else return 0;
    }
    if (i > j)
        return 0;

    int ans = 0;
    for (int k = i + 1; k < j; k += 2) {

        int leftT = ways(str, i, k - 1, true);
        int leftF = ways(str, i, k - 1, false);
        int rightT = ways(str, k + 1, j, true);
        int rightF = ways(str, k + 1, j, false);

        if (str[k] == '&') {
            if (req)
                ans +=  leftT * rightT;
            else {
                ans += leftF * rightF;
                ans += leftT * rightF;
                ans += leftF * rightT;
            }
        } else if (str[k] == '|') {
            if (req) {
                ans += leftT * rightT;
                ans += rightT * leftF;
                ans += rightF * leftT;
            } else
                ans += leftF * rightF;
        } else {
            if (req) {
                ans += leftT * rightF;
                ans += leftF * rightT;
            } else {
                ans += leftT * rightT;
                ans += leftF * rightF;
            }
        }
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

    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    // We obtain the string  T|T&F^T
    int n = s.length();

    cout << ways(s, 0, n - 1, true);
    return 0;
}