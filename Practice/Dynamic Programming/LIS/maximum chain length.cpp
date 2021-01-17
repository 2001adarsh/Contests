#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// Maximum Length Chain LIS
struct val {
    int first;
    int second;
};
int maxChainLen(struct val p[], int n);
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

bool comp(struct val& a, struct val& b) {
    return a.first < b.first;
}
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, comp);
    int dp[n], ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int j = i - 1;

        while (j >= 0) {
            if (p[j].second < p[i].first)
                dp[i] = max(dp[i], dp[j] + 1);
            j--;
        }

        ans = max(ans, dp[i]);
    }
    return ans;
}