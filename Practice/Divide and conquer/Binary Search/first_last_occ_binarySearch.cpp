#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//First and last occurrence using Binary Search.

int first_occurrence(int *arr, int n, int key) {
    int s = 0, e = n - 1;
    int pos = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == key) {
            pos = mid;
            e = mid - 1;
        } else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return pos;
}

int last_occurrence(int *arr, int n, int key) {
    int s = 0, e = n - 1;
    int pos = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == key) {
            pos = mid;
            s = mid + 1;
        } else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return pos;
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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << "Index of first occurrence: " << first_occurrence(arr, n, key) << endl;
    cout << "Index of last occurrence: " << last_occurrence(arr, n, key) << endl;

    return 0;
}