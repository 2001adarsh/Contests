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
		int n, ans = 0, mx;
		cin >> n;

		set<int> st;
		std::vector<int> vec;

		for (int i = 0; i < 2 * n; i++) {
			int x;
			cin >> x;
			if (st.find(x) == st.end()) {
				vec.push_back(x);
				st.insert(x);
			}
		}
		for (auto i : vec)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}