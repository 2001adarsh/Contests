#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

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
        int N;
        cin >> N;
        int arr[N + 2][N + 2];
        memset(arr, 0, sizeof arr);
        int n = N;
        if (n % 2 == 1) {
            n--;
        }
        int pos = -1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) pos += 2;
            for (int j = pos ; j <= pos + 1; j++) {
                arr[i][j] = 1;
            }
        }

        if (N % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            //odd.
            arr[N][N] = 1;
            arr[N][N - 1] = 1;
            arr[N][N - 2] = 1;
            arr[N - 1][N] = 1;
            arr[N - 2][N] = 1;

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}