#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
There are N numbers a[0], a[1]..a[N - 1]. 
The task is to answer some queries. Each query will be 
of the form {L,R}, where you have to count how many numbers 
between indices L and R(inclusive) are divisible by 5.
1
5 4
10 11 45 89 95
1 5
2 4
3 5
4 4
output
3 
1 
2 
0 
*/


void buildTree(ll *arr, ll s, ll e, ll *tree, ll ind){
    //base case
    if(s==e ){
        if(arr[s]%5==0)
            tree[ind] = 1;
        else 
            tree[ind] = 0;
        return;
    }
    //recursive case
    ll mid = s + (e-s)/2;
    buildTree(arr, s,mid, tree, 2*ind);
    buildTree(arr, mid+1, e, tree, 2*ind+1);
    
    tree[ind] = tree[2*ind] + tree[2*ind+1];
}

ll count(ll *tree, ll ind, ll s, ll e, ll qs, ll qe){
    //base case
    if(s>qe || e<qs){ //No overlap
        return 0;
    }
    if(s>=qs && e<=qe){ //Complete overlap
        return tree[ind];
    }
    //recursive case -> partial overlap
    ll mid = s + (e-s)/2;
    ll left = count(tree, 2*ind, s, mid, qs, qe);
    ll right = count(tree, 2*ind+1, mid+1, e, qs, qe);
    return left+right;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }

        ll *tree = new ll[4*n+1];
        buildTree(arr, 0, n-1, tree, 1);
        
        //segmentTree
        for(ll i=1; i<13; i++)
            cout<<tree[i]<<" ";
        cout<<endl;

        while(q--){
            ll l, r;
            cin>>l>>r;
            l -= 1; 
            r -= 1;
            cout<<count(tree, 1, 0, n-1, l, r)<<" ";
            cout<<endl;

        }
    }
    return 0;
}
