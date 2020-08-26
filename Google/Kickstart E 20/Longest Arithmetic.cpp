#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int q = 0;
    while (t--) {
        q++;
        cout << "Case #" << q << ": ";

        int n;
        cin >> n;
        int *arr = new int [n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int start = 0, diff = arr[1] - arr[0], mx = 2;
        int i;
        for (i = 2; i < n; i++) {
            if ( arr[i] - arr[i - 1] != diff) {
                mx = max(mx, i - start);
                //  cout << "1" << " " << mx << ": " << start << endl;
                start = i - 1;
                diff = arr[i] - arr[i - 1];
            } else {
                //  cout << "0" << endl;
            }
        }
        mx = max(mx, i - start);
        cout << mx << endl;
    }

    return 0;
}