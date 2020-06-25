#include <iostream>
using namespace std;
//Replace Bits in N by M in range i to j.

int clearedRangeIJ(int n, int i, int j){
    int ones = (~0);
    int a = ones<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    return n&mask;
}

int replace_bits_n_m(int n, int m, int i, int j){
    int n_ = clearedRangeIJ(n,i,j);
    int mask = m<<i;
    return ((n_)|mask);
}

int main() {     //876543210
    int n= 15;  // 000001111

    int m= 2    // 10
    int i=1, j=3;
    cout<<replace_bits_n_m(n,m,i,j)<<endl; //ans = 000001101 replaced.
}
