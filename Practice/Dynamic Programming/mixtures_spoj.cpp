#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//https://www.spoj.com/problems/MIXTURES/
//Problem is similar to Matrix chain multiplication

// Recurrence:
/*
    Smoke[i][j] = minsmokeat Smoke[i][k] + Smoke[k+1][j] + smoke generated
                    after adding these two(ie, the sum of the values in arr)
*/

int arr[1000];
int dp[1000][1000];

int getAns( int i, int j , int pre[]) {
    if (i >= j) {
        dp[i][j] = 0;
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    //recursive case
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = getAns( i, k, pre) + getAns(k + 1, j, pre);
        int smoke = ((pre[k + 1] - pre[i]) % 100) * ((pre[j + 1] - pre[k + 1]) % 100);
        ans = min(ans, temp + smoke);
    }
    return dp[i][j] =  ans;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    while ((scanf("%lld", &n)) != EOF ) {

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int pre[n + 2] = {};
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + arr[i - 1];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;

        cout << getAns(0, n - 1, pre) << endl;
    }


    return 0;
}