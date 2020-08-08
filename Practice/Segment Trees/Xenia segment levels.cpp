#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

//https://codeforces.com/problemset/problem/339/D
//D. Xenia and Bit Operations

const int N = 1000005;
int arr[N];
int tree[4 * N + 1];

void buildTree(int start, int end, int ind) {
	if (start == end) {
		tree[ind] = arr[start];
		return;
	}
	int mid = start + (end - start) / 2;
	buildTree(start, mid, 2 * ind);
	buildTree(mid + 1, end, 2 * ind + 1);

	//finding the level of segment tree
	int times = log2(end - start + 1);
	if (times & 1)
		tree[ind] = tree[2 * ind + 1] | tree[2 * ind];
	else
		tree[ind] = tree[2 * ind] ^ tree[2 * ind + 1];
}

void updateTree(int start, int end, int qs, int val, int ind) {
	if (start > qs || end < qs) {
		return;
	}
	if (start == end) {
		tree[ind] = val;
		return;
	}
	int mid = start + (end - start) / 2;
	updateTree(start, mid, qs, val, 2 * ind);
	updateTree(mid + 1, end, qs, val, 2 * ind + 1);
	//level
	int times = log2(end - start + 1);
	if (times & 1)
		tree[ind] = tree[2 * ind] | tree[2 * ind + 1];
	else
		tree[ind] = tree[2 * ind] ^ tree[2 * ind + 1];
}


int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	n = pow(2, n);
	for (int i = 0 ; i < n; i++) {
		cin >> arr[i];
	}
	buildTree(0, n - 1, 1);

	while (m--) {
		int i, j;
		cin >> i >> j;
		i--;
		updateTree(0, n - 1, i, j, 1);
		cout << tree[1] << endl;
	}

	return 0;
}