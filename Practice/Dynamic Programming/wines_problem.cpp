#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Wines Problem -
//Improved Time -> O(N^2)

int topDown(int arr[], int s, int e, int yr, int dp[100][100]) {
    if (s == e) {
        dp[s][e] = arr[s] * yr;
        return arr[s] * yr;
    }
    if (dp[s][e] != 0)
        return dp[s][e];
    int ansl = arr[s] * yr + topDown(arr, s + 1, e, yr + 1, dp);
    int ansr = arr[e] * yr + topDown(arr, s, e - 1, yr + 1, dp);
    return dp[s][e] = max(ansl, ansr);
}

//dp[i] = max(dp[i+1][j] , dp[i][j-1])
int BottomUp(int arr[], int n) {
    int dp[100][100] = {0};


    return dp[0][0];
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int dp[100][100] = {0};

    cout << topDown(arr, 0, N - 1, 1, dp);


    return 0;
}