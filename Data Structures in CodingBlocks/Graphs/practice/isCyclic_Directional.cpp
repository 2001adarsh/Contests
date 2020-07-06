#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

const int N = 100005;
vector<ll> v[N];
bool isCyclic = true;
bool vis[N] = { false };
bool recStack[N] = { false };

void dfs(ll node) {
	vis[node] = true;
	recStack[node] = true;

	for (auto nbr : v[node]) {
		if (!vis[nbr])
			dfs(nbr);
		else if (recStack[nbr])
			isCyclic = false;
	}

	recStack[node] = false;
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y); //directed
	}
	for (ll i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
	cout << (!isCyclic);

	return 0;
}