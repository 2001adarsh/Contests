#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

typedef vector< ll > 	vi;
typedef pair< ll,ll > 	ii;

#define pb 		push_back
#define all(c) 		(c).begin(),(c).end()
#define present(c,x) 	((c).find(x) != (c).end())
#define rep(i,n)        for(ll i=0LL; i<(n); i++)

#define MOD 	1000000007
#define INF 	(int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	ll i=2;
	for(i=2; i<499; i++)
	{
		if(n%i==0)
			break;
	}
	cout<<i<<n/i;

	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}