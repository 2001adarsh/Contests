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

void solve()
{
	string s;
	cin>>s;
	string str="";

	ll count=0;
	for(ll i=0; i<s.size(); i++)
	{
		ll x = s[i]-48;
		//cout<<endl<<x<<endl;
		if( x > count )
			{
				for(ll i=count; i<x; i++)
					str +="(";
				str += s[i];	
				count = x;
				// cout<<" "<<count<<" ";
			}
		else if( x < count )
		{
			while(count > x)
			{
				str += ")";
				count--; 
			}
			//cout<<" "<<count<<" ";
			str += s[i];
		}
		else if( x == count)
		{
			str += s[i];
			//cout<<" "<<count<<" ";
		}
	}

	//closing all brackets left
	while(count--)
		str += ")";

	cout<<str<<endl;
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
	for(ll i=1; i<=t; i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	
	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}