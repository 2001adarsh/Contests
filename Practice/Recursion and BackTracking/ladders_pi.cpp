#include <bits/stdc++.h>
using namespace std;

//counting no. of ways to climb a ladder if steps are 1,2,3
int ladder(int n) {
    if(n==0)
        return 1;
    else if(n<0)
        return 0;
    return ladder(n-1) + ladder(n-2) + ladder(n-3); 
}

//replacing pi with 3.14 in string
void pie(string &s, int i){
    if(i >= s.size()-1)
        return;
    if(s[i]=='p' || s[i+1]=='i') {
        s[i]='3'; s[i+1]='.';
        s.insert(i+2,"14");
    }
    pie(s,i+1);
}

int main() {
    string s = "ghspiadfpipi";
    pie(s,0);
    cout<<s<<endl;

    cout<<"Ways of step taken to climb a ladder->"<<ladder(4)<<endl;

}
