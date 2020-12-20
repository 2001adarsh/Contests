#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int decimaltoOctal(int deciNum)
{

    // initializations
    int octalNum = 0, countval = 1;
    int dNo = deciNum;

    while (deciNum != 0) {

        // decimals remainder is calculated
        int remainder = deciNum % 8;

        // storing the octalvalue
        octalNum += remainder * countval;

        // storing exponential value
        countval = countval * 10;
        deciNum /= 8;
    }
    return octalNum;
}

bool check(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++)
        if (str[i] == '7')
            return true;
    return false;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (check(i)) continue;
        int oct = decimaltoOctal(i);
        if (check(oct)) continue;
        // cout << i << " " << oct << endl;
        ans++;
    }
    cout << ans;
    return 0;
}