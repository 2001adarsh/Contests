#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

// https://www.spoj.com/problems/HS08PAUL/
// find the number of (positive) primes not larger than n which are of the form x2+y4 (where x and y are integers).

const int N = 10000025;
vector<int> primes;
bitset<N> pr;

void bitset_primes() {
    pr.set();
    pr[0] = pr[1] = 0; //not prime.
    for (int i = 2; i <= N; i++) {
        if (pr[i] == 1) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                pr[j] = 0;
        }
    }
}

vector<int> sum(N, 0);
vector<int> ge(N, 0);

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    bitset_primes();

    for (int i = 1; i * i <= N; i++)
        ge[i * i] = 1;

    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1];
        if (pr[i] == 1) {
            for (int j = 1; j * j * j * j <= i; j++) {
                if (ge[i - j * j * j * j]) {
                    sum[i]++;
                    break;
                }
            }
        }
    }

    //till points
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << sum[n] << endl;
    }
    return 0;
}