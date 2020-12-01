#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int bracket[1000][1000]; //to store the value of valid k,
//that is the position to break the string.

//algo explained at last.
void printParanthesis(char& name, int i, int j) {
    if (i == j) {
        cout << name;
        name++;
        return;
    }

    cout << "(";
    printParanthesis( name, i,  bracket[i][j] );
    printParanthesis( name, bracket[i][j] + 1, j );
    cout << ")";
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = { 40, 20, 30, 10, 30 };
    int n = sizeof (arr) / sizeof (int);

    n--; //to make one size less. that is actual number of matrices.

    memset(bracket, 0, sizeof bracket);
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap; //the jth position can be found like this.

            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int x = dp[i][k] + dp[k + 1][j] + (arr[i] * arr[k + 1] * arr[j + 1]);
                if (dp[i][j] > x) {
                    dp[i][j] = x;
                    bracket[i][j] = k;
                }
            }
        }
    }


    char name = 'A';
    printParanthesis( name, 0, n - 1);

    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << bracket[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}


/*
// Prints parenthesization in subexpression (i, j)
printParenthesis(i, j, bracket[n][n], name)
{
    // If only one matrix left in current segment -> no need of bracket,
    // just inc the char, for next
    if (i == j)
    {
        print name;
        name++;
        return;
    }

    print "(";

    //here bracket[i][j] = k, the best k, we had earlier found out for the current senario.

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printParenthesis(i, bracket[i][j], bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(bracket[i][j]+1, j, bracket, name);

    print ")";
}


*/