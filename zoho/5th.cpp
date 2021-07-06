#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n; //number of points, inputed.
    cin >> n;

    vector<pair<int, int> > arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());

    int result = 0;
    //counting  -> slope -> points
    for (int i = 0; i < arr.size(); i++) {
        int x1 = arr[i].first, y1 = arr[i].second;
        unordered_map<double, int> mp;
        for (int j = i + 1; j < arr.size(); j++) {
            int x2 = arr[j].first, y2 = arr[j].second;
            double slope = (double)(abs)(y2 - y1) / (double)(abs)(x2 - x1);
            mp[slope]++;
            result = max(result, mp[slope]);
        }
    }

    cout << result + 1;

    return 0;
}