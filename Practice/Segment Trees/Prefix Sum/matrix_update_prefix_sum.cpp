#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
const int N = 6;
//Updating a rectangle portion in matrix. (similar to 1D array update using prefix)
//updating a ranges with values X, and telling the final array.
//using Prefix sum Array.

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int mat[][N] =  {{0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    int q = 1;
    while (q--) {
        int x1, y1, x2, y2, w;
        //here (x1,y1) and (x2,y2) represents the two diagonal points of rectangle.
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        /*
        input:
        1 1 2 2 1
        */

        //for updating those values of rectangle
        mat[x1][y1] += w;
        if (x2 + 1 < N && y2 + 1 < N)
            mat[x2 + 1][y2 + 1] += w;
        if (x2 + 1 < N)
            mat[x2 + 1][y1] -= w;
        if (y2 + 1 < N)
            mat[x1][y2 + 1] -= w;
        //try on pen paper.
    }

    //Now need to find two Prefix sum array, one horizontally and another vertically.
    // For (mXn matrix)
    //vertically
    for (int i = 0; i < N; i++) { //m
        for (int j = 1; j < N; j++) { //n
            mat[j][i] += mat[j - 1][i];
        }
    }
    //horizontally
    for (int i = 0; i < N; i++) { //n
        for (int j = 1; j < N; j++) { //m
            mat[i][j] += mat[i][j - 1];
        }
    }

    //printing
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}