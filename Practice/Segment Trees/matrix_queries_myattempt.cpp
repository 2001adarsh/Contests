#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
const int N = 100005;

int tree[N << 2][2][2], arr[N][2][2];
int r;                          //Result array
void multiply(int **a, int **b, int **c) {
    c[0][0] = (a[0][0] * b[0][0] % r + a[0][1] * b[1][0] % r) % r;
    c[0][1] = (a[0][0] * b[1][0] % r + a[0][1] * b[1][1] % r) % r;
    c[1][0] = (a[1][0] * b[0][0] % r + a[1][1] * b[1][0] % r) % r;
    c[1][1] = (a[1][0] * b[1][0] % r + a[1][1] * b[1][1] % r) % r;
}

void buildTree(int s, int e, int ind) {
    if (s == e) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tree[ind][i][j] = arr[s][i][j];
        return;
    }
    int mid = s + (e - s) / 2;
    buildTree(s, mid, 2 * ind);
    buildTree(mid + 1, e, 2 * ind + 1);
    multiply(tree[2 * ind], tree[2 * ind + 1], tree[ind]);
}

int** query(int s, int e, int qs, int qe, int ind) {
    if (s > qe || e < qs) {
        int** ans = 0;
        ans = new int*[2];
        for (int i = 0; i < 2; i++) {
            ans[i] = new int[2];
        }
        //creation of identity matrix
        ans[0][0] = 1;
        ans[0][1] = 0;
        ans[1][0] = 0;
        ans[1][1] = 1;
        return ans;
    }
    if (s >= qs && e <= qe) {
        int** ans = 0;
        ans = new int*[2];
        for (int i = 0; i < 2; i++) {
            ans[i] = new int[2];
            for (int j = 0; j < 2; j++)
                ans[i][j] = tree[ind][i][j];
        }
        return ans;
    }
    int mid = s + (e - s) / 2;
    int **left = query(s, mid + 1, qs, qe, 2 * ind);
    int **right = query(mid + 1, e, qs, qe, 2 * ind + 1);
    int **ans = new int*[2];
    multiply(left, right, ans);
    return ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> r >> n >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                cin >> arr[i][j][k];
    }

    buildTree(0, n - 1, 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        query(0, n - 1, l, r, 1);
    }

    return 0;
}