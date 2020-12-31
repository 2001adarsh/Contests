#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// C. King's Path
// https://codeforces.com/contest/242/problem/C

/*
The problems uses bfs to move around the grid.
*/


// 8 - positions to move from a box.
int dx[] = {0, -1, 0, 1, -1, 1, 1, -1};
int dy[] = { -1, 0, 1, 0, 1, 1, -1, -1};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int inx, iny , fix, fiy;
    cin >> inx >> iny >> fix >> fiy;
    int n;
    cin >> n;

    set<pair<int, int>> points; // all the valid boxes in the grid.

    while (n--) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++)
            points.insert({r, i});
    }

    //perform bfs from starting.
    map<pair<int, int> , int> mp; //for the distances aur can take as visited array.

    queue<pair<int, int>> Q; // for bfs
    Q.push({inx, iny});
    mp[ {inx, iny}] = 0; // starting position = 0.

    int ans = -1;

    while (!Q.empty()) {
        pair<int, int> node = Q.front();
        Q.pop();

        if (node.first == fix and node.second == fiy) {
            ans = mp[node];
            break;
        }

        //check for the neighbours and add to queue. //bfs
        for (int i = 0; i < 8; i++) {
            int x = dx[i] + node.first;
            int y = dy[i] + node.second;

            // means that is a valid box and box is not encountered yet (!vis).
            if (points.find({x, y}) != points.end() && mp.find({x, y}) == mp.end()) {
                mp[ {x, y}] = mp[node] + 1;
                Q.push({x, y});
            }
        }
    }

    cout << ans;

    return 0;
}