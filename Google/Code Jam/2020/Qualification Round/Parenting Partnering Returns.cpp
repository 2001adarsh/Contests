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
	int n;
	cin>>n;

unordered_map<int,vector<int>> start, end;
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            start[a].push_back(i);
            end[b].push_back(i);
            mini = min(mini,a);
            maxi = max(maxi,b);
        }
        int val = 2;
        vector<char> s(n);
        int C = -1, J = -1;
        int flag = 0;
        for(int i = mini;i<=maxi;i++){
 
            if(end.find(i)!=end.end()){
                if(end[i].size()>2)
                {
                    flag = 1;
                    break;
                }
                for(auto j:end[i]){
                    if(C==j)
                        C=-1;
                    else
                        J=-1;
                    val++;
                }
            }
            if(start.find(i)!=start.end()){
                if(start[i].size()>2)
                {
                    flag = 1;
                    break;
                }
                for(auto j:start[i]){
                    if(C==-1){
                        // cout<<i<<" C\n";
                        s[j]='C';
                        C=j;
                    }
                    else{
                        // cout<<i<<" J\n";
                        s[j]='J';
                        J=j;
                    }
                    val--;
                }
            }
            if(val<0)
            {
                flag = 1;
                break;
            }
        }
        // s[0]='';
        if(val>0 && flag == 0)
        {
            string str ="";
            for(auto i:s){
            	str+=i;
            }
            cout<<str<<'\n';
        }
        else{
        	cout<<"IMPOSSIBLE\n";
        }
}


int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	


	ll t;
	cin>>t;
	for(ll i=1; i<=t; i++){
		cout<<"Case #"<<i<<": ";
		solve();	
	}
	
	// cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}