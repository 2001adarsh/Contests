#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//A sorted array has been rotated and you are asked to find the position
//of the key.

int search(int *arr, int s, int e, int key) {

    while (s <= e) {
        //cout << s << " " << e << " " << endl;
        int mid = s + (e - s) / 2;
//      cout << mid << endl;
        if (arr[mid] == key)
            return mid;

        else if (arr[s] < arr[mid]) {
            if (arr[s] <= key && key <= arr[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else {
            if (arr[mid] <= key && arr[e] >= key)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cin >> key;
    cout << search(arr, 0, n - 1, key);

    return 0;
}