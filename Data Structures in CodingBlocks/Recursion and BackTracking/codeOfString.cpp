#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

list<string> generate(string org, string out, int i, list<string>& li){
    //base case
    if(i==org.size()){
        li.push_back(out);
        //cout<<out<<endl;
        return li;
    }
    //recursive case
    int digit = org[i] - '0';
    char letter = digit + 'a' - 1;
    generate(org, out+letter, i+1, li); //If one letter needed
    if(i != org.size()-1){
        int digit2 = org[i+1] -'0';
        digit = digit*10 + digit2;
        if(digit < 27){
            letter = digit + 'a' -1;
            generate(org, out+letter, i+2, li); // If two letters are selected
        }
    }
    return li;
}

int main(){
    list<string> li;
    string original;
    cin>>original;
    generate(original, "", 0, li);
    cout<<"[";
    
    int i= 0;
    for(auto it = li.begin(); it!= li.end(); it++){
        if(i==li.size() - 1){
            cout<<*it;
        }
        else {
            cout<<*it<<", ";
        }
        i++;
    }

    cout<<"]";
    //cout<<li;
}