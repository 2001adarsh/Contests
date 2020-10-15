#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
int dp[1000005];

//Cell Mitosis->https://hack.codingblocks.com/app/contests/1338/546/problem
//Problem statement at last.
//Top Down.
int Cells(int n, int N, int x, int y, int z, int dp[]) {
    if (n == N)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    int left = INT_MAX, mid = INT_MAX, right = INT_MAX;
    if (n < N) {
        left = x + Cells(2 * n, N, x, y, z, dp);
        mid = y + Cells(n + 1, N, x, y, z, dp);
    } else {
        right = z + Cells(n - 1, N, x, y, z, dp);
    }
    return dp[n] = min(left, min(mid, right));
}

//Bottom Up approach.
int BottomUp(int N, int x, int y, int z) {
    int dp[10005];
    for (int i = 0; i <= 10005; i++)
        dp[i] = INT_MAX;

    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (i & 1) { //odd
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        } else {
            dp[i] = min(dp[i - 1] + y, dp[i / 2] + x);
        }
    }
    return dp[N];
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
    int x, y, z;
    cin >> x >> y >> z;
    memset(dp, 0, sizeof dp);
    cout << Cells(1, n, x, y, z, dp) << endl;
    //cout << BottomUp(n, x, y, z);
    return 0;
}

/*
There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains only a single cell. Now Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways -:

Double the number of cells present in the container.

Increase the number of cells in the container by 1.

Decrease the number of cells in the container by 1.

Now, all the above operations have different costs associated with them x,y,z respectively for above operations. Help brook in finding the minimum cost to generate n cells in the container starting from one cell .
*/