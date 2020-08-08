#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
const int N = 100005;

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
	cin >> n;
	multiset<pair<int, int>, cmp> st;
	int cnt[N] = {0};

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto f = st.find({cnt[x], x});
		if (f != st.end()) {
			st.erase(f);
		}
		st.insert({cnt[x] + 1, x});
		cnt[x]++;
	}

	int q;
	cin >> q;
	for (int j = 0; j < q; j++) {
		char ch; int x;
		cin >> ch >> x;

		if (ch == '+') {
			auto f = st.find({cnt[x] , x});
			if (f != st.end()) {
				st.erase(f);
			}
			st.insert({cnt[x] + 1, x});
			cnt[x]++;
		} else {
			auto f = st.find({cnt[x], x});
			if (f != st.end()) {
				st.erase(f);
			}
			st.insert({cnt[x] - 1 , x});
			cnt[x]--;
		}

		int i = 0;
		int a = 0, b = 0, c = 0;

		for (auto it : st) {
			//	cout << it.first << " " << it.second << endl;
			if (i == 0)
				a = it.first;
			else if (i == 1)
				b = it.first;
			else if (i == 2)
				c = it.first;
			else
				break;
			i++;
		}
		//cout << a << b << c << " ";
		if (a >= 8 || (a >= 6 && b >= 2) || (a >= 4 && b >= 4) || (a >= 4 && b >= 2 && c >= 2) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}