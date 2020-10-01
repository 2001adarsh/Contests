#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Aggressive Cows - SPOJ

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
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);

        for (int i = 0; i < n; i++)
            cin >> stalls[i];

        sort(stalls.begin(), stalls.end());
        int ans = 0;

        //Search space -> 0...stall[n-1]-1;
        int i = 0, j = stalls[n - 1] - 1;

        while (i <= j) {
            int mid = (i + j) / 2;
            int temp = c - 1, k = 1, last = 0;
            while (temp && k < n) {
                if (stalls[k] >= stalls[last] + mid) {
                    last = k;
                    temp--;
                }
                k++;
            }
            if (temp == 0) {
                ans = mid;
                i = mid + 1;
            } else
                j = mid - 1;
        }
        cout << ans << endl;
    }



    return 0;
}
