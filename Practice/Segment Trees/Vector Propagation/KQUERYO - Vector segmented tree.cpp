#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
const int N = 100005;

int arr[N];

struct segmented_tree_vectors
{
	vector<int> st[N * 4]; //segment tree

	void buildTree(int start, int end, int node) {
		if (start == end) {
			st[node].push_back(arr[start]);
			return;
		}
		int mid = start + (end - start) / 2;
		buildTree(start, mid , 2 * node + 1);
		buildTree(mid + 1, end, 2 * node + 2);
		merge(st[2 * node + 1].begin(), st[2 * node + 1].end(), st[2 * node + 2].begin(), st[2 * node + 2].end(), back_inserter(st[node]));
	}

	int query(int start, int end, int qs, int qe, int node, int k) {
		//no overlap
		if (start > qe || end < qs) {
			return 0;
		}
		//complete overlap
		if (start >= qs && end <= qe) {
			return st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
		}
		int mid = start + (end - start) / 2;
		int left = query(start, mid, qs, qe, 2 * node + 1, k);
		int right = query(mid + 1, end, qs, qe, 2 * node + 2, k);
		return left + right;
	}

} tree;


int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	tree.buildTree(0, n - 1, 0);
	int q,  prev_ans = 0;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a ^= prev_ans, b ^= prev_ans, c ^= prev_ans;
		a--, b--;
		prev_ans = tree.query(0, n - 1, a, b, 0, c);
		cout << prev_ans << endl;
	}


	return 0;
}