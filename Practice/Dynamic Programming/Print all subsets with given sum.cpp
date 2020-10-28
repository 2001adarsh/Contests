#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Print all subsets with given sum
//https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/

int dp[1000][1000];
int arr[1000];

void display(vector<int> v) {
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
}

void recur(int N, int sum, vector<int>& vec) {
    if (sum == 0) {
        display(vec);
        return;
    }
    if (N == 0 && dp[N][sum]) {
        vec.push_back(arr[N]);
        display(vec);
        vec.pop_back();
        return;
    }
    //either include this or exclude, but before doing either, check if they are valid or not.
    if (dp[N - 1][sum]) { //means we can get result after excluding
        recur(N - 1, sum, vec);
    }
    if (arr[N] <= sum && dp[N - 1][sum - arr[N]]) { //including.
        vec.push_back(arr[N]);
        recur(N - 1, sum - arr[N], vec);
        vec.pop_back();
    }
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
    memset(dp, 0 , sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][0] = 1;
    }
    int sum; cin >> sum;
    if (arr[0] <= sum) //first element in array in dp.
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j] || ((arr[i] <= j) ? dp[i - 1][j - arr[i]] : 0);
        }
    }

    if (!dp[n - 1][sum]) {
        cout << "False";
        return 0;
    }
    vector<int> vec;
    recur(n - 1, sum, vec);

    return 0;
}