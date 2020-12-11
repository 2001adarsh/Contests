#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        char ch[m][n];
        int pre[m][n];
        memset(pre, 0, sizeof pre);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                cin >> ch[i][j];
                if (ch[i][j] == '*')
                    pre[i][j] = 1;
            }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pre[i][j] += pre[i][j - 1];
            }
        }

        /*      for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++)
                        cout << pre[i][j] << " ";
                    cout << endl;
                }*/


        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[i][j] == '.') continue;
                cnt++;

                char left, right;
                for (int k = 1; k < m - i; k++) {
                    if (k + i >= m)break;
                    if (j - k < 0) break;
                    if (j + k >= n) break;

                    left = ch[k + i][j - k];
                    right = ch[k + i][j + k];

                    int ol = pre[k + i][j + k];
                    int lr = 0;
                    if (j - k - 1 >= 0)
                        lr = pre[k + i][j - k - 1];

                    if (left == right && left == '*' && ol - lr == (2 * k + 1) )
                        cnt++;
                    else break;
                }
                // cout << cnt << " ";
            }
            // cout << endl;
        }
        cout << cnt << endl;
    }

    return 0;
}