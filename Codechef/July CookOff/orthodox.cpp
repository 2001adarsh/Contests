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
		int n;
		cin >> n;
		std::vector<int> v(n);

		bool flag = false;
		set<int> s;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s.insert(v[i]);
		}

		int y = v[0];
		for (int i = 1; i < n; i++) {
			y = v[i] | y;
			//cout << y << " ";
			if (s.find(y) == s.end())
				s.insert(y);
			else flag = true;
		}
		if (flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}