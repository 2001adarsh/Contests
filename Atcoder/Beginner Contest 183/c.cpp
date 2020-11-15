#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int N = 10;
int n, k;
int mat[N][N];
bool vis[N];
int ans = 0;

void dfs(int x, int sum) {
    vis[x] = true;
    bool flag = false;
    for (int nbr = 0; nbr < n; nbr++) {
        if (nbr != x && (!vis[nbr]) ) {
            dfs(nbr, sum + mat[x][nbr]);
            flag = true;
        }
    }
    if (!flag) {
        if (sum + mat[x][0] == k)
            ans++;
    }
    vis[x] = false;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    memset(vis, false, sizeof vis);
    dfs(0, 0);
    cout << ans;

    return 0;
}