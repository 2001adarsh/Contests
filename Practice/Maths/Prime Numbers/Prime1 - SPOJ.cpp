#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.spoj.com/problems/PRIME1/
// Using Segmented Seive.

const int N = 1e6;
int pr[N];
vector<int> primes;

void seive(int x) {
    int i, j;
    for (i = 2; i <= x; i++) { // O(N loglogN)
        if (!pr[i]) {
            primes.push_back(i);
            for (j = i * i; j <= x; j += i) {
                pr[j] = 1;
            }
        }
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int sqn = 1e5;
    seive(sqn);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        if (m == 1) m++;
        if (m > n) {cout << endl; continue;}

        int arr[n - m + 1] = {0}; //initialised as prime to all.

        for (int i = 0; i < primes.size(); i++) { // for all primes.

            if (primes[i] * primes[i] > n) break;

            int start = (m / primes[i]) * primes[i];

            if (primes[i] >= m and primes[i] <= n)
                start = 2 * primes[i];

            for (int j = start; j <= n; j += primes[i])
                if (j - m >= 0)
                    arr[j - m] = 1;
        }

        for (int i = 0; i < n - m + 1; i++)
            if (!arr[i])
                cout << i + m << endl;
        cout << endl;
    }

    return 0;
}