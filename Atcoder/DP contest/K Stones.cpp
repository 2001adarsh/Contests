#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

const int N = 100005;
int dp[N];
int arr[N];

//Recursive + Memoization.
bool fun(int K, int n) {
    if (dp[K] != -1)
        return (!dp[K]);
    for (int i = 0; i < n; i++) {
        if (arr[i] <= K) {
            if (!fun(K - arr[i], n)) {
                dp[K] = 0;
                return true;
            }
        }
    }
    dp[K] = 1;
    return false;
}

//DP bottom up solution.
void bottomUp(int n, int K) {
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= K; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (i >= arr[j]) {
                flag = flag || (!dp[i - arr[j]]);
            }
        }
        dp[i] = flag;
    }

    // for (int i = 0; i <= K ; i++)
    //  cout << dp[i] << " ";
    if (dp[K])
        cout << "First";
    else
        cout << "Second";
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, K;
    cin >> n >> K;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /*memset(dp, -1, sizeof dp);
    if (fun(K, n))
        cout << "First";
    else
        cout << "Second";*/
    bottomUp(n, K);
    return 0;
}