#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll board[1000][1000], m, n;

void generate( ll i, ll j , ll& size, vector< vector<ll> >& check) {
	//base case
	if (i < 0 || j < 0 || i >= m || i >= n || board[i][j] == 0 || check[i][j] == 1) {
		return;
	}

	//recursive case
	board[i][j] = 0;
    check[i][j] = 1;
    size++;
	generate( i + 1, j, size, check);
	generate( i - 1, j, size, check );
	generate(  i, j + 1, size, check );
	generate(  i, j - 1, size,check );
	board[i][j] = 1;
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	ll sum = 0;
	//Work
	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < n; j++) {
			if (board[i][j] == 0) {

				board[i][j] = 1;
				ll ans = 0;
                vector< vector<ll> > check(m, vector<ll> (n,0));
				generate(i, j, ans, check);
				//cout << i << " " << j << " " << ans << endl;
				sum = max(sum, ans);

				board[i][j] = 0;
			}
		}
	}
	cout << sum;

	return 0;
}