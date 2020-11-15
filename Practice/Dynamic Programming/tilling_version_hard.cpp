#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// https://www.geeksforgeeks.org/tiling-with-dominoes/
// Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.

/*
An =  No. of ways to completely fill a 3 x n board. (We need to find this)
Bn =  No. of ways to fill a 3 x n board with top corner in last column not filled.
Cn =  No. of ways to fill a 3 x n board with bottom corner in last column not filled.
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int A[n + 1] , B[n + 1];
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);

    A[0] = 1; A[1] = 0;
    B[0] = 0; B[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = A[i - 2] + (2 * B[i - 1]);
        B[i] = A[i - 1] + B[i - 2];
    }
    cout << A[n];

    return 0;
}