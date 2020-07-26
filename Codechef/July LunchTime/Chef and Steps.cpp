#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string ans = "";
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % k == 0)
				ans += "1";
			else ans += "0";
		}
		cout << ans << endl;
	}

	return 0;
}