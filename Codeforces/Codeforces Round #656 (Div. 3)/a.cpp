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
		int x, y, z;
		cin >> x >> y >> z;

		if (x != y && y != z && z != x) {
			cout << "NO" << endl;
		} else if (x == y || z == x || y == z) {
			if (x == y && y == z ) {
				cout << "YES" << endl;
				cout << x << " " << x << " " << x << endl;
			} else {
				int a = max(x, max(y, z));
				int cnt = 0;
				if (a == z)
					cnt++;
				if (a == x)
					cnt++;
				if (a == y)
					cnt++;

				if (cnt == 2) {
					int b = min(x, min(y, z));
					int c = 1;
					cout << "YES" << endl;
					cout << a << " " << b << " " << c << endl;

				} else {
					cout << "NO" << endl;
				}
			}
		}
	}

	return 0;
}