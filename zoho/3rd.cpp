#include<bits/stdc++.h>
using namespace std;
#define int long long int

//char, index
unordered_map<char, int> mp;

bool comp(pair<int, char>& a, pair<int, char>& b) {
    if (a.first == b.first)
        return mp[a.second] < mp[b.second];
    return a.first > b.first;
}

int32_t main()
{

    string input;
    cin >> input;

    // int charset[27];
    // memset(charset, 0 , sizeof charset);

    // for (int i = 0; i < input.size(); i++) {
    //  charset[input[i] - 'a']++;
    //  if (mp.count(input[i]) == 0)
    //      mp[input[i]] = i;
    // }

    // vector<pair<int, char>> Q;

    // for (int i = 0; i < 26; i++)
    //  Q.push_back({charset[i], i + 'a'});

    // sort(Q.begin(), Q.end(), comp);
    // string result = "";
    // for (int j = 0; j < Q.size(); j++) {
    //  pair<int, char> largestChar = Q[j];
    //  for (int i = 0; i < largestChar.first; i++)
    //      result += largestChar.second;
    // }
    // cout << result;


    vector<pair<int, char>> Q;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '.') continue;

        mp[input[i]] = i;
        int cnt = 1;
        for (int j = i + 1; j < input.size(); j++) {
            if (input[i] == input[j])
                input[j] = '.', cnt++;
        }
        Q.push_back({cnt, input[i]});
    }

    // for (int i = 0; i < Q.size(); i++)
    // cout << Q[i].first << " " << Q[i].second << endl;

    sort(Q.begin(), Q.end(), comp);
    string result = "";
    for (int j = 0; j < Q.size(); j++) {
        pair<int, char> largestChar = Q[j];
        for (int i = 0; i < largestChar.first; i++)
            result += largestChar.second;
    }
    cout << result;

    return 0;
}