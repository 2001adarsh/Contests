#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Number of Primes in a Range. a<=10e6 and b<=10e6 and N<10000

const int N = 1e6;
int pr[N] = {0};

void seive() {
    for (int i = 3; i <= N; i += 2)
        pr[i] = 1;

    for (int i = 3; i <= N; i += 2) {
        if (pr[i] == 1)
            for (int j = i * i; j <= N; j += i)
                pr[j] = 0;
    }
    pr[2] = 1;
    pr[1] = pr[0] = 0;
}

// to store number of prime numbers in range.
int pref[N] = {0};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    seive();
    for (int i = 1; i <= N; i++) {
        pref[i] = pr[i] + pref[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        //number of prime numbers here.
        int ans = pref[y] - pref[x - 1];
        cout << ans << endl;
    }

    return 0;
}