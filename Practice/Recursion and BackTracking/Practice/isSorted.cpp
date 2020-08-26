#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

int sorted(int *arr, int n) {
    if (n == 1)
        return 1;
    return (arr[n - 1] < arr[n - 2]) ? 0 : sorted(arr, n - 1);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << sorted(arr, 6);

    return 0;
}
