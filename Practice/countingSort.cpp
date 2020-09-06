#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Counting Sort

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int arr[] = {1, 2, 3, 3, 1, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    int *cnt = new int[10000];
    int *sortedArr = new int[n];

    for (int i = 0; i < 10000; i++)
        cnt[i] = 0;

    for (int i = 0 ; i < n; i++)
        cnt[arr[i]]++;

    //prefix sum
    for (int i = 1; i < n; i++)
        cnt[i] += cnt[i - 1];

    for (int i = 10000; i > 0; i--) {
        cnt[i] = cnt[i - 1];
    }
    cnt[0] = 0;

    for (int i = 0; i < n; i++) {
        sortedArr[cnt[arr[i]]] = arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
        cout << sortedArr[i] << " ";

    return 0;
}