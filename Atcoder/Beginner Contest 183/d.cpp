#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

const int N = 200005;

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    cin >> n >> w;
    int arr[N];
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        arr[s] += p;
        arr[t] -= p;
    }
    bool flag = true;
    if (arr[0] > w) {
        cout << "No";
        return 0;
    }

    for (int i = 1; i < N; i++) {
        arr[i] += arr[i - 1];
        if (arr[i] > w) {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}