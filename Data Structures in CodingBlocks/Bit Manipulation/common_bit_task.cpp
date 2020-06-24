#include <iostream>
using namespace std;

bool isOdd(int n){
    return n&1;
}

int getBit(int n, int i){
    int mask = 1<<i;
    return (n&mask) > 0 ? 1 : 0 ; //could also've been written like n&(1<<i)
}

int setBit(int n, int i){
    return (n|(1<<i));
}

int clearBit(int n, int i){
    int mask = ~(1<<i);
    return n&mask;
}

int updateBit(int n, int i, int v){
    int mask = ~(1<<i);
    int cleared_n = n&mask;
    return cleared_n|(v<<i);
}

// -1 or ~0 returns 11111...
// whereas -> -1<<i returns 11111000 i number of zeros. 
int clearLastIth(int n, int i){
    int mask = (-1<<i);  
    return n&mask;
}


// 10100101 
//&11110011 -> mask
//will give ans. but to acheive mask
// 11110000 - a
//|00000011 - b OR of a and b will give mask

int clearRangeIJ(int n, int i, int j){
    int ones = (~0);
    int a = ones<<(i+1);
    int b = (1<<j) -1; //for 00000111 it is 2^i -1.
    int mask = a|b;
    return n&mask;
}

int main() {
    int n =5;
    int i;
    cin>>i;

    cout<<isOdd(n)<<endl;
    //getting the ith bit from right
    cout<<getBit(n, i)<<endl;
    //setting the ith bit from right
    n = setBit(n, i);
    cout<<n<<endl;

    cout<<clearBit(n,0)<<endl;
    cout<<updateBit(n,2,0)<<endl;

    n=15;
    cout<<clearLastIth(n, 2)<<endl;
    n=31;
    cout<<clearRangeIJ(n, 3,1)<<endl; //10001
}
