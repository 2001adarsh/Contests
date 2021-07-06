#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18

//DP in Trees
//Finding a smallest node number in subtree x.

const int N = 1e5 + 5;
vector<int> gr[N];
int dp[N];

void dfs(int curr, int par) {
    dp[curr] = curr;
    for (int x : gr[curr])
        if (x != par) {
            dfs(x, curr);
            dp[curr] = min(dp[curr], dp[x]);
        }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v); //tree
        gr[v].push_back(u);
    }

    //root is 1
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        cout << i << " " << dp[i] << endl;

    return 0;
}

/*
8 10
1 2
1 4
2 8
8 6
8 10
6 9
4 3
4 5
5 7

*/