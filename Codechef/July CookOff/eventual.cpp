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
		string s;
		cin >> s;

		char ch[27] = {0};
		for (int i = 0; i < n; i++) {
			ch[s[i] - 'a']++;
		}
		bool flag = false;
		for (int i = 0; i < 27; i++) {
			if (ch[i] & 1)
				flag = true;
		}
		if (flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}


	return 0;
}