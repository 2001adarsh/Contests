#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Generic Trees:
/*
Better Approach: First child / Next sibling representation
In first child/next sibling representation, the steps taken are:

At each node link the children of same parent(siblings) from left to right.
Remove the links from parent to all children except the first child.
Memory efficient – No extra links are required, hence lot of memory is saved.

- Treated as binary trees – Since we are able to convert any generic tree to
binary representation, we can treat all generic trees with a first child/next
sibling representation as binary trees.Instead of left and right pointers,
 we just use firstChild and nextSibling.
*/

//Representation:
struct Node {
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
}
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}