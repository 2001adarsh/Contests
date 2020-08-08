#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set<string> st;
void substring(string str){
    //base case
    if(str.size() == 0)
        return;
    //recursive case
    for(int i=0; i<=str.size(); i++){
        for(int j=0; j<str.size()-i; j++){
            substring(str.substr(i,j));
            string s = string(str.rbegin(), str.rend());
            if(str == s)
                st.insert(str);
        }
    }
}
//reversing a number -> method 1 used for checking palindrome
int rev(int n){
    //base case
    if(n < 10)
        return n;
    //recursive case
    int num = rev(n/10);
    int si = (int)log10(num) + 1; 
   // cout<<((n%10)*pow(10,si) +num)<<endl;
    return ((n%10)*pow(10,si) +num);
}

//method 2 -> checking palindrome in a function
bool onedigit(int n){
    return (n>=0 && n <10);
}
bool rev2(int n, int *orign) {
    //base case
    if(onedigit(n)){ //contains only one digit
        return n%10 == (*orign)%10;
    }
    //recursive case
    if(!rev2(n/10, orign)) {
        return false;
    }
    *orign /=10;
    return (n%10 == (*orign)%10); //from begining in n, and last in finaln
}

int main() {
   
   //finding all palindrome of a string
   substring("nitin");
   for(auto a: st)
    cout<<a<<" ,";
    cout<<endl;

    //check if a number is a palindrome or not
    int c= rev(2442);
    cout<<c<<endl;
    if(c == 2442) 
        cout<<"It is a palindrome"<<endl;
    else 
        cout<<"It is not a palindrome"<<endl;

    int num = 2442;
    int *dupNum = &num; //passing pointer to dupNum
    if(rev2(num,dupNum))
        cout<<"true";
    else cout<<"false";
}
