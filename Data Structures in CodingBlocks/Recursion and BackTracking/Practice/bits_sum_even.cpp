#include <iostream>
using namespace std;

//Find all even length binary sequences with same sum of first and second half bits

void evenlength(int n, string out, int ones, int zeroes) {
    //base case
    if(out.size() == 2*n){
        cout<<out<<endl;
        return;
    }
    //recursive case
    if(out.size() < n) {
        evenlength(n, out+'1', ones+1, zeroes);
        evenlength(n, out+'0', ones, zeroes+1);
    } else{
        if( ones == (n - (out.size() - n)) ){
            evenlength(n,out+'1', ones-1, zeroes);
        } else if(zeroes == (n-(out.size()-n))){
            evenlength(n, out+'0', ones, zeroes-1);
        } else{
        evenlength(n, out+'1', ones-1, zeroes);
        evenlength(n, out+'0', ones, zeroes-1);
        }
    }
}

int main() {
    evenlength(3, "", 0,0);
}
