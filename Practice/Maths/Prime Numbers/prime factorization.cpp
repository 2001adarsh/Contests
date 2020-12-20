#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Prime factorization:
map<int, int> fact;

//naive approach -> O(N)
void naive() {
    int F = 66; //find prime factorization of this num.
    for (int i = 2; i <= F; i++) {
        if (F % i == 0) {
            while (F % i == 0) {
                F = F / i;
                fact[i]++;
            }
        }
    }
    for (auto num : fact)
        cout << num.first << " " << num.second << endl;
}


//Optimised Approach - O(sqrt(N))
/*
using the fundamental to check if the num is prime or not
dividing the array into two parts on sqrt(N), that is if there is a element
less than sqrt(N) then there will be an element greater than it to divide.
*/
void Optimised(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n = n / i;
                fact[i]++;
            }
        }
    }
    if (n != 1)  // the number left is prime number.
        fact[n] = 1;

    for (auto num : fact)
        cout << num.first << " " << num.second << endl;
}


// Seive Based Approach
/*
This approach is helpful for queries related problem, as precomputation will require
O(NloglogN)
and each query will require just O(logN) time.

O(NloglogN) [precomputation] + O(logN) for each query.
*/
const int N = 1e5;
vector<bool> pr(N + 1, false);
vector<int> primes;

void seive() {
    pr[0] = pr[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!pr[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                pr[j] = true;
        }
    }
}
//factorize the number in logN time.
void factorize(int num) {

    for (auto p : primes) {
        if (num < p * p) break; // stopping criteria, as all prime number will be less than sqrt(N), or it will be the prime number itself.
        if (num % p == 0) {
            while (num % p == 0) {
                fact[p]++;
                num = num / p;
            }
        }
    }
    if (num != 1) //when the number is prime in itself.
        fact[num]++;

    for (auto f : fact)
        cout << f.first << " " << f.second << endl;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    // naive();
    // Optimised(66);

    seive();
    factorize(66);


    return 0;
}