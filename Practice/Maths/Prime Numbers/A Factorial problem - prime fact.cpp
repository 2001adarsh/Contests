#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

/*
Mike found an interesting problem. In this
 problem you are given two integers, n and k. You need to find the the maximum value
 of x, such that, n! % pow(k,x) = 0.
*/

const int N = 1e6;
vector<bool> pr(N, true);
vector<int> primes;

void seive() {
    pr[0] = pr[1] = false;
    for (int i = 2; i <= N; i++) {
        if (pr[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                pr[j] = false;
        }
    }
}

map<int, int> prime_factorization(int n) {
    map<int, int> mp;
    for (auto p : primes) {
        if (p * p > n) break;

        if (n % p == 0) {
            while (n % p == 0) {
                mp[p]++;
                n = n / p;
            }
        }
    }
    if (n != 1)  //that means the left over is prime.
        mp[n] = 1;
    return mp;
}

int factors(int n, const int k) {
    int ans = 0;

    for (int i = k; i < n; i *= k) {
        if ( (n / i) > 0)
            ans += (n / i);
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

    seive();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        //prime factorization of k.
        map<int, int> mpk = prime_factorization(k);

        //finding the pow of prime factors of k in n!
        int x = inf;
        for (auto f : mpk) {
            int cnt = factors(n, f.first);
            if (cnt < f.second) {
                x = 0;
                break;
            }
            x = min(x, cnt / f.second);
        }
        cout << x << endl;
    }
    return 0;
}