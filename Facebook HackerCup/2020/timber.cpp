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
	int t, k = 0;
	cin >> t;
	while (t--) {
		k++;
		cout << "Case #" << k << ": ";
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A')
				a++;
			else b++;
		}
		if (abs(a - b) == 1) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}

	return 0;
}