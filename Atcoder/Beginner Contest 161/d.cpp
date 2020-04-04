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

bool lucky(ll n) 
{ 
    // Initalize prevDigit with -1 
    ll prevDigit = -1; 
  
    // Iterate through all digits of n and compare difference 
    // between value of previous and current digits 
    while (n) 
    { 
        ll curDigit = n % 10; 
  
        if (prevDigit == -1) 
            prevDigit = curDigit; 
        else
        { 
            if ( !(abs(prevDigit - curDigit) <= 1)) 
                 return false; 
        } 
        prevDigit = curDigit; 
        n /= 10; 
    } 
  
    return true; 
} 

int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	if(n<=12)
		cout<<"n";
	else{
		ll count=12;
		ll i=20;
		for(i=20; true; i++)
		{
			if(lucky(i))
				count++;
			if(count == n)
				break;
		}
		cout<<i;

	}
	

	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}