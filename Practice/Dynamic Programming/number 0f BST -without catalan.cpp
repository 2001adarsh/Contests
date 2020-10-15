#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
/*
Number of Binary Search Tree which can be formed with 1..N nodes,
https://leetcode.com/problems/unique-binary-search-trees/

for a particular node
so left subtree would be numberofBST formed by i-1 nodes which will be smaller than i.
and right subree would be numberofBST formed by N-i nodes(nodes greater than i)
and now all the nodes could be root node, hence find for all nodes.

This problem could also be solved using CATALAN number:
    (2n C n)/n+1

Number of binary trees -> n*(numberofBST(n)) -> this is becase in that structure
we can permute the positions of each node.

Number of unlabelled trees (structural) -> numberofBST(n)  as BST gives all unique structures.
*/

//Time Complexity = O(N)
int numberofBST(int N, int dp[]) {
    //0 or 1 nodes are 1 way.
    if (N == 0 || N == 1)
        return 1;
    if (dp[N] != 0)
        return dp[N];
    //taking each node as root node once, computing
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += numberofBST(i - 1, dp) * numberofBST(N - i, dp); //total ways when i is root.
    }
    return dp[N] = sum;
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
    int dp[1000] = {};
    cout << numberofBST(n, dp);

    return 0;
}