#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

/*
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
a row of n coins of values v1 . . . vn, where n is even. We play a game against
an opponent by alternating turns. In each turn, a player selects either the
first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the
maximum possible amount of money we can definitely win if we move first.
*/

//Top Down approach
int game(int arr[], int n, int i, int j) {
    if (i == j)
        return arr[i];
    if (i > j)
        return 0;
    //computing only for first player's move
    int first = arr[i];
    first +=  min(game(arr, n, i + 2, j), game(arr, n, i + 1, j - 1)); //array left after, opponent picks either first or last element.
    //since opponent is playing optimally, he will reduce the price. so min() taken.

    int last = arr[j];
    last += min( game(arr, n, i + 1, j - 1) , game(arr, n, i, j - 2));
    return max(first, last);
}
// game(arr, n, i + 1, j - 1) this case is common, hence overlapping problem -> DP


//Bottom Up Approach
int bottom(int arr[], int n) {
    int table[n][n];

    //to traverse the matrix, diagonally
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            int x = (i + 2 <= j) ? table[i + 2][j] : 0;
            int y = (i + 1 <= j - 1) ? table[i + 1][j - 1] : 0;
            int z = (i <= j - 2) ? table[i][j - 2] : 0;

            table[i][j] = max(arr[i] + min(x, y) , arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << game(arr, n, 0, n - 1) << endl;
    cout << bottom(arr, n);
    //opponents score could be found after subtracting from total score.

    return 0;
}