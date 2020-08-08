#include <iostream>
using namespace std;

//Fast exponentiation using Bitmask.

int power_optimised(int a, int n){
    int ans = 1;
    while(n>0){
        int last_bit = n&1;
        if(last_bit){
            ans *= a;
        }
        a *= a;
        n = n>>1;
    }
    return ans;
}

int main() {
    int a = 2, n = 6;
    cout<<power_optimised(a,n)<<endl; //2^6 = 64
}
