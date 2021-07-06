#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool solve(string str1, string str2) {
    if (str1.size() != str2.size())
        return false;

    unordered_map<char, char> mp;
    for (int i = 0; i < str1.size(); i++) {
        if (mp.count(str1[i]) == 1) {
            if (mp[str1[i]] != str2[i])
                return false;
        }
        mp[str1[i]] = str2[i];
    }
    return true;
}

int32_t main()
{

    string str1, str2;
    cin >> str1 >> str2;

    if (solve(str1, str2))
        cout << "true";
    else
        cout << "false";

    return 0;
}