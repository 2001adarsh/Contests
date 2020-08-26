#include<bits/stdc++.h>
using namespace std;
#define endl    "\n"
#define inf 1000000000000000000ll

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds_set;

//for multiple values in set
// pair<value, index>
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds_multiset;


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    pbds_set St;

    St.insert(23);
    St.insert(3);
    St.insert(13);
    St.insert(2);
    St.insert(53);
    St.insert(3);

    for (int i = 0; i < St.size(); i++) {
        //returns an iterator to the k - th largest element (counting from zero)
        cout << i << " -> " << *St.find_by_order(i) << endl;
    }

    //Returns elements it is greater than.
    cout << St.order_of_key(3) << endl;

    pbds_multiset mst;
    mst.insert({1, 4});
    mst.insert({1, 2});
    mst.insert({3, 2});
    mst.insert({2, 2});

    for (int i = 0; i < mst.size(); i++)
        cout << mst.find_by_order(i)->first << " " << mst.find_by_order(i)->second << endl;

    return 0;
}