#include <iostream>
using namespace std;

//forming pairs of closed brackets in right ways.

void backets(int n ,string s, int left, int right) {
    //base case
    if( s.size() == 2*n ){
        cout<<s<<endl;
        return;
    }
    //recursive case
    if(right>left)
        return;

    if( left == n )
        backets(n, s+')', left, right+1);
    else{
        backets(n, s+'(', left+1, right);
        backets(n, s+')', left, right+1);
    }
}

//method two
void generate(int n, string s, int left, int right) {
    //base case
    if(s.size() == 2*n){
        cout<<s<<endl;
        return;
    }
    //recursive case
    if(left < n)
        generate(n, s+'(', left+1, right);
    
    if(right < left)
        generate(n, s+')', left, right+1);
    return;
}

int main() {
    backets(3, "", 0,0);
    cout<<"Method 2"<<endl;
    generate(3,"", 0, 0);
}
