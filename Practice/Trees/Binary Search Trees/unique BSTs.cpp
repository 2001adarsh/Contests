#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//For key values from 1...n, how many structurally unique BST's are possible.

//find for every element from 1 to n, so if we take x as root node,
// x-1 will be at its left and n-x elements will be at its right.
// then recursively find the total number of BST's possible.

int countTrees(int n) {
    if (n <= 1)
        return 1;
    int sum = 0;
    for (int root = 1; root < n; root++) {
        int left = countTrees(root - 1);
        int right = countTrees(n - root);
        sum += left * right; // because there are left*right ways.
    }
    return sum;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << countTrees(5);
    return 0;
}