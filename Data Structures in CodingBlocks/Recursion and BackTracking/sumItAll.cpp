#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< ll > 	vi;
typedef pair< ll, ll > 	ii;

#define endl 		"\n"
#define pb		push_back
#define all(c) 		(c).begin(),(c).end()
#define rep(i,n)	for(ll i=0LL; i<(n); i++)
#define MOD 		1000000007
#define INF 		(int)1e9
#define MEM(a, b) 	memset(a, (b), sizeof(a))

double tick() {static clock_t oldt, newt = clock(); double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC; oldt = newt; return diff;}

set< vi > sep;

bool generate(vi inp, ll i, vi& out, ll sum) {
	//base case
	if ( sum == 0 ) {
		sep.insert(out);
		return false;  //If true, will return only one answer.
	}
	if (i == inp.size())
		return false;

	//recursive case
	ll digit = inp[i];
	if (digit <= sum) {
		out.push_back(digit);
		bool ans = generate(inp, i + 1, out, sum - digit);
		if (ans == true) {
			return true;
		}
		else {
			out.pop_back();
			return generate(inp, i + 1, out, sum);
		}
	}
	return false;
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	vi out;
	ll n;
	cin >> n;
	vi inp(n);

	for (ll i = 0; i < n; i++) {
		cin >> inp[i];
	}

	ll target;
	cin >> target;

	sort(all(inp));

	generate(inp, 0, out, target);

	for (auto i : sep) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}
