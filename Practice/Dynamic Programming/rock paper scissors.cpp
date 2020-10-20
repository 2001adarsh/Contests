#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

int dp[100][100][100];

double f1(int R, int P, int S) { //Rock wining
    if (R == 0 || S == 0)
        return 0.0;
    if (P == 0)
        return 1.0;
    if (dp[R][S][P] != -1)
        return dp[R][S][P];
    double ret = 0.0;
    double total = (R * S) + (P * R) * (S * P);
    ret += f1(R - 1, P, S) * (R * P) / total; //Paper kills rock
    ret += f1(R, P, S - 1) * (S * R) / total; //Rock kills scissor
    ret += f1(R, P - 1, S) * (S * P) / total; //Scissor kills paper
    return dp[R][S][P] = ret;
}

double f2(int R, int P, int S) { //Scissor wining
    if (P == 0 || S == 0)
        return 0.0;
    if (R == 0)
        return 1.0;
    if (dp[R][S][P] != -1)
        return dp[R][S][P];
    double ret = 0.0;
    double total = (R * S) + (P * R) * (S * P);
    ret += f2(R - 1, P, S) * (R * P) / total; //Paper kills rock
    ret += f2(R, P, S - 1) * (S * R) / total; //Rock kills scissor
    ret += f2(R, P - 1, S) * (S * P) / total; //Scissor kills paper
    return dp[R][S][P] = ret;
}

double f3(int R, int P, int S) { //Paper wining
    if (P == 0 || R == 0)
        return 0.0;
    if (S == 0)
        return 1.0;
    if (dp[R][S][P] != -1)
        return dp[R][S][P];
    double ret = 0.0;
    double total = (R * S) + (P * R) * (S * P);
    ret += f3(R - 1, P, S) * (R * P) / total; //Paper kills rock
    ret += f3(R, P, S - 1) * (S * R) / total; //Rock kills scissor
    ret += f3(R, P - 1, S) * (S * P) / total; //Scissor kills paper
    return dp[R][S][P] = ret;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int r, p, c;
    cin >> r >> p >> c;
    double p1 = f1(r, p, c); //probability of rock wining.
    double p2 = f2(r, p, c); //probabilty of scissor wining.
    double p3 = f3(r, p, c); //Probability of paper wining.

    cout << fixed << setprecision(9) << p1 << " " << p2 << " " << p3 << endl;
    return 0;
}