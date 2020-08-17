#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll
int n;

int getResult(vector<int> freq) {
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n - i; j++) {
            int s = 0;
            for (int k = j; k < j + i; k++) {
                s = min(i, freq[k]);
                if (s < i)
                    break;
            }
            if (i == s) {
                ans = i;
                break;
            }
        }
    }
    return ans;
}

int left(vector<vector<char>> mat) {
    vector<int> freq;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'D')
                cnt++;
        }
        freq.push_back(cnt);
    }
    int ans = getResult(freq);
    return ans;
}

int down(vector<vector<char>> mat) {
    vector<int> freq;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 'D')
                cnt++;
        }
        freq.push_back( cnt);
    }
    int ans = getResult(freq);
    return ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    vector<vector<char> > mat(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int a = left(mat);
    int b = down(mat);
    if (a > b)
        cout << a;
    else
        cout << b;

    return 0;
}