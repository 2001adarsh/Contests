#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

int32_t main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size(), m = t.size();
    
    map<char, int> map_s, map_t;
    for(auto x: t)  map_t[x]++;

    int l=0, rightl=-1 , rightr= 1e9;
    for(int r=0; r<n; r++){
        bool good = true;
        map_s[s[r]]++;

        for(auto x: map_t){
            if(map_s.count(x.first) == 0 || map_s[x.first] < x.second)
                good = false;
        }
        if(!good) continue;

        while(l<=n && l<=r && (map_t.count(s[l])==0 || map_t[s[l]] < map_s[s[l]])){
            map_s[s[l]]--;
            if(map_s[s[l]] == 0) map_s.erase(s[l]);
            l++;
        }

        //cout<<l<<" "<<r<<endl;

        if(rightr-rightl+1 > r-l+1){
            rightr = r;
            rightl = l;
        }
    }

    if(rightl == -1){
        cout<<"No String";
    }else{
        cout<<s.substr(rightl, rightr - rightl+1);
    }

    return 0;
}