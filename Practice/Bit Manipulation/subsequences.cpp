#include <iostream>
#include <cstring>
using namespace std;
//Finding the subsequences of any string.
/*
   it will contain 2^n subbsets , as every alphabet has two options
   either it will be selected or not.
   hence we can represent it in the loop of binary numbers from
   0 to 2^N-1 (it can also be written as (1<<N)-1 ).
   and each bit in this loop defines if the element is going to be selected
   or not.
*/

void filterchars(int n, char a[]){
    int j=0;
    while(n>0){
        if(n&1){ //if last bit is positive then, we include that letter, so print it.
            cout<<a[j];
        }
        j++;
        n = n>>1;
    }
    cout<<endl;
}

void printSubsequence(char a[]){
    int n = strlen(a);
    for(int i=0; i<(1<<n); i++){
        filterchars(i, a);
    }
}

int main() {
    char a[] = {"abc"};
    printSubsequence(a);

}
