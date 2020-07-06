#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"
const int N = 1000005;
std::vector<ll> v[N];
bool vis[N] = {false};
bool used[N] = {false};
stack<ll> order;

void dfs(ll node) {
	vis[node] = true;
	for (auto nbr : v[node]) {
		if (!vis[nbr]) {
			dfs(nbr);
		}
	}
	order.push(node);
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
		v[x].push_back(y);
	}

	for (ll i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	while (!order.empty())
	{
		cout << order.top() << " ";
		order.pop();
	}

	return 0;
}