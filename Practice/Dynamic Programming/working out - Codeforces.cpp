#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

/*
    Working Out - Codeforces https://codeforces.com/problemset/problem/429/B
    In this problem have to make max dp from all corners, and then try to
    partition at every (x,y) coordinate and check for the maximum.
*/


int n, m;
int dp1[1005][1005]; //max path from top left to bottom right.
int dp2[1005][1005]; //max path from bottom left to top right.
int dp3[1005][1005]; //max path from bottom right to top left.
int dp4[1005][1005]; //max path from top right to bottom left.

int board[1005][1005]; //my board.

void topLeft() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp1[i][j] = board[i][j];
            else if (i == 0)
                dp1[i][j] = dp1[i][j - 1] + board[i][j];
            else if (j == 0)
                dp1[i][j] = dp1[i - 1][j] + board[i][j];
            else
                dp1[i][j] = max( dp1[i - 1][j], dp1[i][j - 1]) + board[i][j];
        }
    }
    /*  for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp1[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
}

void bottomLeft() {
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i == m - 1 && j == 0)
                dp2[i][j] = board[i][j];
            else if (i == m - 1)
                dp2[i][j] = dp2[i][j - 1] + board[i][j];
            else if (j == 0)
                dp2[i][j] = dp2[i + 1][j] + board[i][j];
            else
                dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + board[i][j];
        }
    }
    /*  for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
}

void bottomRight() {
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1)
                dp3[i][j] = board[i][j];
            else if (i == m - 1)
                dp3[i][j] = dp3[i][j + 1] + board[i][j];
            else if (j == n - 1)
                dp3[i][j] = dp3[i + 1][j] + board[i][j];
            else
                dp3[i][j] = max(dp3[i + 1][j], dp3[i][j + 1]) + board[i][j];
        }
    }
    /*  for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp3[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
}

void topRight() {
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == 0 && j == n - 1)
                dp4[i][j] = board[i][j];
            else if (i == 0)
                dp4[i][j] = dp4[i][j + 1] + board[i][j];
            else if (j == n - 1)
                dp4[i][j] = dp4[i - 1][j] + board[i][j];
            else
                dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + board[i][j];
        }
    }
    /*  for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp4[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    topLeft();
    bottomLeft();
    bottomRight();
    topRight();
    //Now my max DP's are ready.
    //only to compute which combination will give the best result.
    int ans = 0;
    for (int i = 1 ; i < m - 1 ; i++) {
        for (int j = 1; j < n - 1; j++) {
            //case 1: boy comming from top and girl comming from left
            int case1 = dp1[i - 1][j] + dp2[i][j - 1] + dp3[i + 1][j] + dp4[i][j + 1];
            //case 2: boy comming from left and girl comming from down.
            int case2 = dp1[i][j - 1] + dp2[i + 1][j] + dp3[i][j + 1] + dp4[i - 1][j];
            ans = max(ans, max(case1, case2));
        }
    }
    cout << ans;

    return 0;
}

/*
4 5
87882 40786 3691 85313 46694
28884 16067 3242 97367 78518
4250 35501 9780 14435 19004
64673 65438 56977 64495 27280

747898
*/