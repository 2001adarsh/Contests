// Space optimisation version of Seive of Eratosthenes.
// More range of N can be stored in array.
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
/*
bool prime[100]; will take 100 * 8 bits memory
bitset<100> will take 100 bits memory only, so better than bool prime[].
which, on most systems, is eight times less than the smallest elemental type: char)
For safety, dont increase range more than 10e7
*/
const int N = 10e7;
bitset<N> pr; // array containing numbers from 1...n

vector<int> primes; // to store all the primes numbers.

void bitset_seive() {
    pr.set(); //set all as prime
    pr[0] = pr[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (pr[i] == 1) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                pr[j] = 0;
        }
    }
}

bool isPrime(int n) {
    //if n is less than 10^7, see directly in bitset and return O(1)
    if (n <= N) {
        return pr[n];
    }

    //O(sqrt(N))
    for (int i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    bitset_seive();

    //printing top 50 primes;
    for (int i = 0; i < 50; i++)
        cout << primes[i] << " ";
    cout << endl;

    //We can check if N = (10^7)^2 that is till (10^14) is prime or not
    //by this method as it requires only sqrt(N) times of checking of a factor.
    cout << isPrime(2147483647) << endl;
    //10 - digit prime number

    cout << isPrime(136117223861) << endl;
    // not a prime, 104729*1299709

    return 0;
}

// bitset starts its indexing backward that is for 10110, 0 are at 0th and 3rd indices whereas 1 are at 1st 2nd and 4th indices.

/*
    BITSET KNOWLEDGE

    // count function returns number of set bits in bitset
    int numberof1 = set8.count();

    // size function returns total number of bits in bitset
    // so there difference will give us number of unset(0)
    // bits in bitset
    int numberof0 = set8.size() - numberof1;

    // test function return 1 if bit is set else returns 0
    cout << "bool representation of " << set8 << " : ";
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";

    // any function returns true, if atleast 1 bit
    // is set
    if (!set8.any())
        cout << "set8 has no bit set.\n";

        // none function returns true, if none of the bit
    // is set
    if (!bset1.none())
        cout << "bset1 has all bit set\n";

         // bset.set() sets all bits
    cout << set8.set() << endl;

    //  bset.set(pos, b) makes bset[pos] = b
    cout << set8.set(4, 0) << endl;

    aset.reset();
    bset.flip();

    // Converting decimal number to binary by using bitset
    int num = 100;
    cout  << "\nDecimal number: " << num
         << "  Binary equivalent: " << bitset<8>(num);
  cout<<endl;

*/