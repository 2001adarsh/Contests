#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> prices;
int fee;

int maxProfit(int i, bool isBought, int prev) {
    if (i == prices.size())
        return 0;

    if (isBought == false) {
        //buy a stock

        //buy at i,
        int buy = maxProfit(i + 1, true, prices[i]);
        int leave = maxProfit(i + 1, isBought, prev);

        return max(buy, leave);

    } else {
        //try to sell a stock

        //sell at i
        int sell = 0;
        if (prices[i] > prev)
            sell = (prices[i] - prev - fee) + maxProfit(i + 1, false, -1);
        int leave = maxProfit(i + 1, isBought, prev);

        return max(sell, leave);
    }
    return -1;
}


int32_t main()
{
    int n;
    cin >> n;
    prices.resize(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cin >> fee;


    cout << maxProfit(0, false, -1);


    return 0;
}