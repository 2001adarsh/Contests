#include<bits/stdc++.h>
using namespace std;

/*
You are given a dictionary consisting of N words each containing lowercase letters 'a'-'z'.
You also have MxM crossword consisting of lowercase letters 'a'-'z'. You want to print all possible
words that can be formed by a sequence of adjacent characters. Note that you can move to any of 8
 adjacent characters, but a word should not have multiple instances of same cell. Note :- if a word
  is present in crossword more than once print it once.

input
2
a aa
2
aa
aa
output : a aa

*/
char grid[6][6];
vector<string> vc;
set<string> st;

void solve(int m, int i, int j, string ans){
    //base case
    if(i>=m || j>=m || i<0 || j<0 || grid[i][j] == '.'){
        return;
    }
    //recursion case
    char ch = grid[i][j];
    grid[i][j] = '.';
    ans += ch;
    if(find(vc.begin(), vc.end(), ans) != vc.end()){
        st.insert(ans);
    }

    solve( m, i+1, j+1, ans);
    solve( m, i, j+1, ans);
    solve(m, i+1, j, ans);
    solve( m, i+1, j-1, ans);
    solve( m, i, j-1, ans);
    solve( m, i-1, j-1, ans);
    solve( m, i-1, j, ans);
    solve( m, i-1, j+1, ans);
    grid[i][j] = ch;
}

int main(){
    //initialising grid to '.'
    for(int i=0; i<6; i++){
        for(int j=0;j<6; j++){
            grid[i][j] = '.';
        }
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        vc.push_back(s);
    }

    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            solve(m, i, j, "");
        }
    }
    for(auto i: st){
        cout<<i<<" ";
    }
}
