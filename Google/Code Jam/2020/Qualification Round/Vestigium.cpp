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


void solve(){
	ll n;
	cin>>n;

	ll a[n][n];
	ll ans1=0, ans2=0, ans3=0;

	rep(i,n){
		rep(j,n)
		{
			cin>>a[i][j];
			if(i==j)
				ans1+=a[i][j];
		}
	}

	//for ans2;
	rep(i,n){
		set<ll> s;
		rep(j,n){
			s.insert(a[i][j]);
		}
		if(s.size()!=n)
			ans2++;
	}

	//for ans3;
	rep(i,n){
		set<ll> s;
		rep(j,n){
			s.insert(a[j][i]);
		}
		if(s.size()!=n)
			ans3++;
	}

	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
}


int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll t;
	cin>>t;
	for(ll i=1; i<=t; i++)
	{
		cout<<"case #"<<i<<": ";
		solve();
	}

	
	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}