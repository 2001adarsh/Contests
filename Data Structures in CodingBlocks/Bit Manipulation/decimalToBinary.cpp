#include <iostream>
using namespace std;

int decimalToBinary(int n){
    int ans =0;
    int p10 = 1;
    while(n){
        int last_bit= n&1;
        ans += last_bit*p10;
        p10 *= 10;
        n = n>>1;
    }
    return ans;
}


int main() {
    cout<<decimalToBinary(13)<<endl;
}
