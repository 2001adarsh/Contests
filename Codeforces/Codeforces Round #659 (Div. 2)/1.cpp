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
		int n, m;
		set<int> st;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			st.insert(x);
		}
		bool flag = false;
		int element = 0 ;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (st.find(x) != st.end()) {
				flag = true;
				element = x;
			}
		}

		if (flag) {
			cout << "YES" << endl << 1 << " " << element << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}