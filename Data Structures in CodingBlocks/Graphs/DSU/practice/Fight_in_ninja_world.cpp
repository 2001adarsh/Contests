#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
const int N = 200005;
std::vector<int> parent;

// Finding oponents using DSU.
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/

int superParent(int x) {
	if (parent[x] == -1)
		return -1;
	if (parent[x] == 1)
		return 1;
	if (parent[x] == 2)
		return 2;
	return parent[x] = superParent(parent[x]);
}

void unite(int x, int y) { //using concept of DSU

	int sx = superParent(x);
	int sy = superParent(y);

	if (sx == 1 || sy == 2) {
		parent[y] = 2;
		parent[x] = 1;
	} else if (sx == 2 || sy == 1) {
		parent[x] = 2;
		parent[y] = 1;
	} else {
		parent[x] = 1;
		parent[y] = 2;
	}
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, j = 0;
	cin >> t;
	while (t--) {
		parent.clear();
		parent.resize(N);
		for (int i = 0; i <= N; i++) {
			parent[i] = -1 ;
		}

		int n;
		cin >> n;
		while (n--) {
			int x, y;
			cin >> x >> y;
			unite(x, y);
		}
		int c1 = 0, c2 = 0;
		for (int i = 0; i < 11; i++) {
			cout << parent[i] << " ";
			if (parent[i] == 1)
				c1++;
			else if (parent[i] == 2)
				c2++;
		}
		j++;
		cout << "Case " << j << ": " << max(c1, c2) << endl;
	}

	return 0;
}