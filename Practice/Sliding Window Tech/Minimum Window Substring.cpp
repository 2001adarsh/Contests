#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Minimum Window Substring

string minWindow(string s, string t) {
    if (t.size() > s.size())
        return "";

    char sfreq[256] = {0};
    char tfreq[256] = {0};

    for (int i = 0; i < t.size(); i++)
        tfreq[t[i]]++;

    int st_idx = -1, min_window = INT_MAX, start = 0, cnt = 0;

    for (int end = 0; end < s.size(); end++) {
        sfreq[s[end]]++;

        if (tfreq[s[end]] != 0 and sfreq[s[end]] <= tfreq[s[end]])
            cnt++;

        if (cnt == t.size()) {
            //contraction
            while ( tfreq[s[start]] == 0 or sfreq[s[start]] > tfreq[s[start]]) {
                sfreq[s[start]]--;
                start++;
            }

            //got a window
            int window = end - start + 1;
            if (window < min_window) {
                min_window = window;
                st_idx = start;
            }
        }
    }
    if (st_idx == -1)
        return "";
    return s.substr(st_idx, min_window);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string word, get;
    cin >> word >> get;

    cout << minWindow(word, get);


    return 0;
}