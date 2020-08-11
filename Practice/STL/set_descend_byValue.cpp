#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
struct cmp
{
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;

	multiset<pair<int, int>, cmp> st;
	int cnt[100] = {0};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto f = st.find({cnt[x], x});
		if (f != st.end()) {
			st.erase(f);
		}
		st.insert({cnt[x] + 1, x});
	}
	return 0;
}