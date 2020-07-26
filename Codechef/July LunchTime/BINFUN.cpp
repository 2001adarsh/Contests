#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

string binaryRep(int x) {
	string ans = "";
	while (x > 0) {
		if (x & 1)
			ans += "1";
		else
			ans += "0";
		x >>= 1;
	}
	return ans;
}

int BinaryConcatenation(int x, int y) {
	string binX = binaryRep(x);
	string binY = binaryRep(y);

	reverse(binX.begin(), binX.end());
	reverse(binY.begin(), binY.end());


	string xpy = binX + binY;
	string ypx = binY + binX;

	x = std::bitset<64>(xpy).to_ulong();
	y = std::bitset<64>(ypx).to_ulong();
	//cout << binX << " " << binY << " : " << x << " " << y << endl;
	return x - y;
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	//cout << BinaryConcatenation(1, 128) << endl;
	while (t--) {
		int n;
		cin >> n;
		std::vector<int> v(n);
		int mi = INT_MAX, mx = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mi = min(mi, v[i]);
			mx = max(mx, v[i]);
		}
		/*
				int ans = INT_MIN;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						ans = max(ans, BinaryConcatenation(v[i], v[j]));
					}
				}*/

		sort(v.begin(), v.end());

		int lastEven = 0, firstOdd = 0, firstEven = 0, lastOdd = 0;

		for (int i = 0; i < n; i++) {
			if (firstEven == 0 && v[i] % 2 == 0) {
				firstEven = v[i];
			} else if (firstOdd == 0 && v[i] & 1) {
				firstOdd = v[i];
			}

			if (v[i] & 1) {
				lastOdd = v[i];
			} else
				lastEven = v[i];
		}

		int asn = max(BinaryConcatenation(firstOdd, lastEven ) , BinaryConcatenation(lastOdd, firstEven)) ;
		cout << max(asn, BinaryConcatenation(mi, mx)) << endl;
		//	cout << ans << endl;

	}

	return 0;
}