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

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n],b[n];
		rep(i,n) cin>>a[i];
		rep(i,n) cin>>b[i];

		if(a[0] != b[0]) { cout<<"NO"<<endl; continue; }
		else{
			bool flag=true;
			
			ll x=0,y=0; //x for -1 and y for 1
			for(ll i=0; i<n; i++)
			{
				if(b[i]<a[i] && x==0) { flag=false; break; }
				if( b[i]>a[i] && y==0) { flag=false; break; }

				if(a[i]== -1)
					x++;
				else if(a[i]==1)
					y++;
			}

			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			
		}	
	}
		
	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}