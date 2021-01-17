#include <bits/stdc++.h>
using namespace std;

// Maximum  Chain - Printing.
struct val {
    int first;
    int second;
};

bool comp(struct val& a, struct val& b) {
    return a.first < b.first;
}
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, comp);
    int dp[n], ans = 0;
    int parent[n];
    memset(parent, -1, sizeof parent);
    int start = 0; //start printing from

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int j = i - 1;

        while (j >= 0) {
            if (p[j].second < p[i].first and dp[j] + 1 > dp[i]) {
                dp[i] =  dp[j] + 1;
                parent[i] = dp[j];
            }
            j--;
        }
        if (ans < dp[i]) {
            ans = dp[i];
            start = i;
        }
    }

    //print the maximum chain.
    while (parent[start] != -1) {
        cout << p[start].first << " " << p[start].second << endl;
        start = parent[start];
    }
    cout << p[start].first << " " << p[start].second << endl;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
