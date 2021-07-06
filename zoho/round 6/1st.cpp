#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18


int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    /*
    O(N^2)
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";

    cout<<dp[n];*/

    set<int> st;
    for (int i = 0; i < n; i++) {
        auto itr = st.lower_bound(arr[i]);
        if (itr != st.end())
            st.erase(itr);
        st.insert(arr[i]);
    }
    cout << st.size();

    return 0;
}