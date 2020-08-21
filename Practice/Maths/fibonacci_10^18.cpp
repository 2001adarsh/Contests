#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
/*  An amazing way to calculate 10^18-th fibonacci number using 25 lines of code.
By kien_coi_1997

let f(n) be the (n + 1) th fibonacci number, we have two case:
 n is even and n is odd.

f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)
f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)

in O(log)
*/

const int M = 1000000007; // modulo
map<int, int> F; //Stores Fibonacci

int f(int n) {
    if (F.count(n)) return F[n];
    int k = n / 2;
    if (n % 2 == 0) { // n=2*k
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    } else { // n=2*k+1
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    F[0] = F[1] = 1;
    while (cin >> n)
        cout << (n == 0 ? 0 : f(n - 1)) << endl;

    return 0;
}