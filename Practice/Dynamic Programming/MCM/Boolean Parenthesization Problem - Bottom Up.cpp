#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Boolean Parenthesization Problem | DP-37
// Bottom Up approach.

/*
SImilar to MCM, find number of Trues and False in each step, and calculate
for each operator at every position.
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);

    //create dp array.
    int T[n + 1][n + 1];     //For # of true
    int F[n + 1][n + 1];    // For # of false.
    memset(T, 0, sizeof T);
    memset(F, 0, sizeof F);


    for (int i = 0; i < n; i++) {
        if (symbols[i] == 'T') T[i][i] = 1;
        else F[i][i] = 1;
    }

    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;

            for (int k = i; k < j; k++) {

                //total
                int leftT = T[i][k] + F[i][k];
                int rightT = T[k + 1][j] + F[k + 1][j]; //right total - both # of true and false.

                if (operators[k] == '&') {
                    T[i][j] += T[i][k] * T[k + 1][j];
                    // F[i][j] += F[i][k] * F[k+1][j];
                    F[i][j] += (leftT * rightT) - (T[i][k] * T[k + 1][j]); //explained below
                } else if (operators[k] == '|') {
                    F[i][j] += F[i][k] * F[k + 1][j];
                    T[i][j] += (leftT * rightT) - (F[i][k] * F[k + 1][j]);
                } else {
                    T[i][j] += (T[i][k] * F[k + 1][j]) + (F[i][k] * T[k + 1][j]);
                    F[i][j] += (T[i][k] * T[k + 1][j]) + (F[i][k] * F[k + 1][j]);
                }
            }
        }
    }

    cout << T[0][n - 1];
    return 0;
}

/*
For AND,
 both the elements should be true for the T[i][j] to be true, so its straightforward.
 but for false,
 any of the value can be false. Hence, anything apart from {T,T} results the ans.
 ie,
  Total values - # true on both sides
    =
     #true * #false
     #false * #true
     #false * #false
*/