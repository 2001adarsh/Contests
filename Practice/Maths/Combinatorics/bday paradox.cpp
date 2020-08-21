#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll
//The BirthDay Paradox.

/* The minimum number of people that should be present in the Hall so that
    there's 50% chance of two people having the same b'day ?
*/
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // x denotes the probability of having different b'days.
    float x  = 1.0;
    int people = 0;
    float num = 365; //numerator
    float denom = 365; //denominator

    float p;
    cin >> p; // The % of chance we need of people having same bday.
    // to be entered as 0.5 as 50%.

    while (x > 1 - p) {
        // x is less than the threshhold
        x = x * (num) / denom;
        num--;
        people++;
    }
    cout << "The number of People having same bday(50%): " << people << endl;

    return 0;
}