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
		std::vector<int> inp(n);
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> inp[i];
			mx = max(mx, inp[i]);
		}

		string first = "";
		for (int i = 0; i < mx; i++) {
			first += (char)(97 + (i % 26));
		}
		bool flag = false;
		for (int i = 0 ; i < n; i++) {
			if (inp[i] > 0)
				flag = true;
		}
		if (!flag) {

			for (int i = 0; i < n + 1; i++) {
				char ch = (char)(97 + (i % 26) );
				cout << ch << endl;
			}
			continue;
		}

		cout << first << endl;

		for (int i = 0; i < n; i++) {
			string s = "";
			int val = inp[i];

			for (int i = 0; i < val; i++) {
				s += first[i];
			}
			for (int j = val; j < mx; j++) {
				s += (char)(97 + ((first[j] - 'a') + 1) % 26);
			}
			cout << s << endl;
			first = s;
		}

	}

	return 0;
}