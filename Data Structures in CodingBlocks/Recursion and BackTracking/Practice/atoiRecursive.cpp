#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< ll > 	vi;
typedef pair< ll, ll > 	ii;

#define endl 		"\n"
#define pb			push_back
#define all(c) 		(c).begin(),(c).end()
#define rep(i,n)	for(ll i=0LL; i<(n); i++)
#define MOD 		1000000007
#define INF 		(int)1e9
#define MEM(a, b) 	memset(a, (b), sizeof(a))

double tick() {static clock_t oldt, newt = clock(); double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC; oldt = newt; return diff;}

set<string> v;

void permute(vector<char> st, ll k, string s) {
	if (s.size() == k) {
		v.insert(s);
		return ;
	}
	for (ll i = 0; i < st.size(); i++) {
		permute(st, k, s + st[i]);
		//cout << s << endl;
	}
}

//atoi() implementation using recursion -> string to integer
int atoi(string s) {
    //base case
    if(s.size() <= 0)
        return -1;
    //recursive case
    string str = s;
    str.pop_back();
    int result = atoi(str);
    if(result == -1){
        return (s[s.size()-1] - '0');
    }
    return (result*10 + (s[s.size()-1] -'0') );
}


int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<char> st;
	st.pb('a');
	st.pb('b');
	st.pb('a');

	permute(st, 3, "");
	for (set<string>::iterator a : v)
		cout << *a << endl;

    //conversion of string to integer using recursion.
    cout<<atoi("234")<<endl;

	 cout<<"\nExecution time : "<<tick()<<"\n";
	return 0;
}
