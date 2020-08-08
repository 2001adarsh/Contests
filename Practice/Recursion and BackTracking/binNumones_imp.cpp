#include <iostream>
using namespace std;

//Count number of binary strings without consecutive 1’s
int binarystring(int n) {
    if(n==0 || n==1)
        return n+1;
    return binarystring(n-1)+ binarystring(n-2);
}

int main() {
    cout<<binarystring(4);
}
