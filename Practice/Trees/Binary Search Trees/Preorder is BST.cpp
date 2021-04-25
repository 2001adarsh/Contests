#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Check if a given array can represent Preorder Traversal of Binary Search Tree

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    stack<int> st;
    bool flag = true;
    int pre_root = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre[i] < pre_root) {
            flag = false;
            break;
        }
        while (!st.empty() and pre[i] > st.top()) {
            pre_root = st.top();
            st.pop();
        }
        st.push(pre[i]);
    }

    cout << flag;

    return 0;
}