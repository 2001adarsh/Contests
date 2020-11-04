#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int dp = 0;
    int result = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            dp = 1 + dp;
            result += dp;
        }
        else
            dp = 0;
    }
    return result;
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
    vector<int> A(n + 1);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << numberOfArithmeticSlices(A);

    return 0;
}