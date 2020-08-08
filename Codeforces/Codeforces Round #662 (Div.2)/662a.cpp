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
		cout << (n / 2) + 1 << endl;
	}

	return 0;
}