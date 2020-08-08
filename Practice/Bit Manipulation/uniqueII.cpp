#include <bits/stdc++.h>
using namespace std;
// Has only 2 unique numbers and the rest are in pairs.
// find those 2 unique number. without any extra space.

int posOfLastSetBit(int n){
    int position = 0;
    while(n>0){
        if(n&1==1){
            return position;
        }
        position++;
        n = n>>1;
    }
    return position;
}

int getBit(int n,int i){
    int mask = 1<<i;
    return (n&mask)>0 ? 1 : 0;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int result =0 ; //store XOR of all the number.
    for(int i=0; i<n; i++){
        cin>>v[i];
        result ^= v[i];
    }
    int pos = posOfLastSetBit(result);

    vector<int> havingSetBit;
    for(int i=0; i<n; i++){
        if(getBit(v[i], pos)){
            havingSetBit.push_back(v[i]);
        }
    }

    int first =0;
    for(auto it: havingSetBit){
        first ^= it;
    }
    int second = result^first;
    if(first<second){
        cout<<first<<" "<<second;
    }else{
        cout<<second<<" "<<first;
    }
}
