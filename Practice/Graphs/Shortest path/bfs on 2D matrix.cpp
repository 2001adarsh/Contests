#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/

#define N 4
#define M 4
//up r, d, left
int dr[] = { -1, 0, 1, 0 };
int dc[] = {0, 1, 0, -1};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char grid[N][M] = { {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '0', '0', '0'}
    };

    int si = 0, sj = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 's') {
                si = i, sj = j;
                break;
            }
        }

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    queue<pair<int , int>> Q;

    Q.push({si, sj});
    Q.push({ -1, -1});
    vis[si][sj] = true;
    int level = 0, ans = -1;

    while (!Q.empty()) {
        pair<int, int> pr = Q.front();
        Q.pop();

        int x = pr.first, y = pr.second;
        if (x == -1 && y == -1) {
            level++;
            pair<int, int> cur = Q.front();
            if (cur.first == -1)
                break;
            Q.push({ -1, -1});
            continue;
        }

        if (grid[x][y] == '0') {
            vis[x][y] = true;
            continue;
        }

        if (grid[x][y] == 'd') {
            ans = level;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int rr = x + dr[i], cc = y + dc[i];

            //out of bound.
            if (rr < 0 || cc < 0 || rr >= N || cc >= M)
                continue;

            //rr, cc -> child current node. push queue.
            if (vis[rr][cc] == false) {
                Q.push({rr, cc});
                vis[rr][cc] = true;
            }
        }
    }

    cout << ans;
    return 0;
}

/*
{'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'} = 6
*/