#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

//updating a ranges with values X, and telling the final array.
//using Prefix sum Array.

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 6;
    int arr[n] = {0};

    int q = 3;
    while (q--) {
        /* input:
        0 2 100
        1 5 50
        2 3 20
        */
        int x, y, up;
        cin >> x >> y >> up;
        arr[x] += up;
        if (y + 1 < n)
            arr[y + 1] -= up;
    }

    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1]; //taking prefix sum
        cout << arr[i] << " ";
    }
    return 0;
}