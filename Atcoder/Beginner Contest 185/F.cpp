#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
void buildTree(int *arr, int s, int e, int *tree, int ind) {
    if (s == e)
    {
        tree[ind] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    buildTree(arr, s, mid, tree, 2 * ind );
    buildTree(arr, mid + 1, e, tree, 2 * ind + 1);
    tree[ind] = tree[2 * ind] ^ tree[2 * ind + 1];
}

void pointUpdate(int *tree, int ind, int s, int e, int update, int value) {
    if (s == e && s == update) {
        tree[ind] = tree[ind] ^ value;
        return;
    }
    if (!(update >= s && update <= e)) {
        return;
    }
    int mid = (s + e) / 2;
    pointUpdate(tree, 2 * ind, s, mid, update, value);
    pointUpdate(tree, 2 * ind + 1, mid + 1, e, update, value);
    tree[ind] = tree[2 * ind] ^ tree[2 * ind + 1];
}

int ans(int *tree, int ind, int s, int e, int qs, int qe) {
    if ( s >= qs && e <= qe ) {
        return tree[ind];
    }
    if (e < qs || qe < s) {
        return 0;
    }
    int mid = (s + e) / 2;
    int a = ans(tree, 2 * ind, s, mid, qs, qe);
    int b = ans(tree, 2 * ind + 1, mid + 1, e, qs, qe);
    return a ^ b;
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int *tree = new int[4 * n + 1];
    buildTree(arr, 0, n - 1, tree, 1);

    for (int i = 0; i < q; i++) {
        int u, x, y;
        cin >> u >> x >> y;
        if (u == 1) {
            x--;
            pointUpdate(tree, 1, 0, n - 1, x, y);
        } else {
            x--, y--;
            cout << ans(tree, 1, 0 , n - 1, x, y) << endl;
        }
    }
    return 0;
}