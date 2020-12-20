#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.interviewbit.com/problems/scramble-string/

map< pair<string, string>, bool > mp;

bool isScrambled(string s1, string s2) {
    //base case.
    if (s1 == s2)
        return true;

    if (s1.size() != s2.size())
        return false;

    if (mp.find({s1, s2}) != mp.end())
        return mp[ {s1, s2}];

    //recursive case
    int n = s1.size();
    //partitioning every angle, into a binary and checking for scambled strings matching.
    for (int k = 1; k < n; k++) {

        //checking if front side of s1, is scambled to be back side of s2,
        // meaning that the strings are swapped after the partition, to make the string scambled.
        // ie, they are swapped around k.
        if ( isScrambled(s1.substr(0, k), s2.substr(n - k, k) ) &&
                isScrambled(s1.substr(k, n - k), s2.substr(0, n - k)) )
            return true;

        // if they are not swapped.
        if ( isScrambled(s1.substr(0, k), s2.substr(0, k)) &&
                isScrambled(s1.substr(k, n - k), s2.substr(k, n - k)))
            return true;
    }
    return mp[ {s1, s2}] = false;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    cout << isScrambled(s1, s2);

    return 0;
}