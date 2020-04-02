#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin>>s;
	int x = s[s.size()-1] - 48;
	if(x%2)
		cout<<"1";
	else cout<<"0";

	return 0;
}