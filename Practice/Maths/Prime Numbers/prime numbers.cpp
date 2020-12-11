#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Naive method - O(N)
bool isPrime(int N) {
    if (N == 1)
        return true;
    if (N == 2)
        return false;
    for (int i = 2; i < N; i++) {
        if (N % i == 0)
            return false;
    }
    return true;
}

//Little optimisation - O(sqrt(N))
bool isPrime2(int N) {
    if (N == 1)
        return true;
    if (N == 2)
        return false;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0)
            return false;
    }
    return true;
}

// Sieve Approach: array of prime numbers.
// O(NloglogN) -> approximately linear.
// N = 10e6 will be maximum in this case.

void seive(int *p) {

    //marking all odd numbers as prime - as they can be potential prime numbers. We are directly skipping even numbers.
    for (int i = 3; i <= 100000; i += 2) {
        p[i] = 1;
    }

    for (int i = 3; i <= 100000; i += 2) {
        //if current number is marked prime, mark its multiples as not prime.
        if (p[i] == 1) {
            for (int j = i * i; j <= 100000; j += i) //first encounter will be at i*i, instead of 2*i
                p[j] = 0;
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;
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
    int p[100005] = {0};
    seive(p);

    // printing of prime numbers.
    for (int i = 0; i <= n; i++) {
        if (p[i] == 1) {
            cout << i << " ";
        }
    }


    return 0;
}