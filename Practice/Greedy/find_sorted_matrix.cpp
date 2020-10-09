#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
//Finding the element in a sorted matrix.
/*
    Matrix sorted both in row wise, and column wise.

*/
int element;
void solve(int mat[4][4], int n, int m) {
    int i = 0, j = m - 1; //Top right corner
    int ai = -1, aj = -1; //Result storage.
    while (i < n && j >= 0) {
        if (mat[i][j] == element) {
            ai = i, aj = j;
            break;
        }
        if (mat[i][j] > element)
            j--;
        else
            i++;
    }
    cout << ai << ", " << aj;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 27, 29, 37, 48 },
        { 32, 33, 39, 50 }
    };
    cin >> element;
    solve(mat, 4, 4);

    return 0;
}