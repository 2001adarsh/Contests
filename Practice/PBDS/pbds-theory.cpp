#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


The tree - based container has the following declaration:

template <
    // Key type - int , pair<int, int> etc.
    typename Key,
    // Mapped-policy or null_type - for set policy
    typename Mapped,

    // Key comparison functor
    typename Cmp_Fn = std::less<Key>,

    // Specifies which underlying data structure to use
    //splay_tree_tag  - for splay tree
    // ov_tree_tag - ordered vectored tree
    // rb_tree_tag - red black tree
    typename Tag = rb_tree_tag,

    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_ >
    //tree_order_statistics_node_update
    class Node_Update = null_node_update, // A policy for updating node invariants
    typename Allocator = std::allocator<char> > // An allocator type
class tree;


//example:
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;



//Functions:
1. find_by_order() -> returns an iterator to the k - th largest element (counting from zero)

2. order_of_key() -> the number of items in a set that are strictly smaller than our item
basically a LowerBound on vectors.


Best part is -> Both the operations take O(logN) time complexity.

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    return 0;
}