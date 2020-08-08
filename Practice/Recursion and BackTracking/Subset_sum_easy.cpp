#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
if the sum of any of the non-empty subsets of the set A is zero.
1
4
1 3 2 -3
output Yes.
*/

string solve(ll *arr, ll n, ll i,ll sum, ll& val)
{
    //base case
    if(i==n+1){
        return "No";
    }
    if(sum == 0 && val != 0){
        return "Yes";
    }
    //recursive case
    //cout<<sum<<val<<endl;
    val++;
    string with = solve(arr, n, i+1, sum+arr[i],val);
    val--;
    string without = solve(arr, n, i+1, sum, val);
    
    if(with=="Yes" || without =="Yes"){
        return "Yes";
    }
    return "No";
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        ll val=0;
        cout<<solve(arr, n, 0, 0, val)<<endl;
    }    

}
