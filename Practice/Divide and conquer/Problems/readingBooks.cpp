#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Reading Books
/*
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.
*/

int search(int *arr, int s, int e, int m, int n) {
    int ans = -1;

    while (s <= e) {
        int mid = (s + e) / 2;

        bool valid = true;
        //Check if it could be valid.
        int t = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                sum = arr[i];
                t++;
                if (t > m) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) { //valid move. search for the more best ans.
            ans = mid;
            e = mid - 1;
        } else
            s = mid + 1;
    }
    return ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << search(arr, arr[n - 1], sum, m, n);

    return 0;
}