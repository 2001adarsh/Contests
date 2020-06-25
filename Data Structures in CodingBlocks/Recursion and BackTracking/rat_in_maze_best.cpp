#include <bits/stdc++.h>
using namespace std;

char grid[1000][1000];
int board[1000][1000];

bool solve(int i, int j, int n, int m){
    //base case
     if(i==n-1 && j== m-1){
        board[i][j] = 1;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return true;  //could also have printed the answer, and did exit(0);
    }
    if( i>=n || j>=m || grid[i][j] == 'X'){
        return false;
    }

    //recursive case
    board[i][j] = 1;
    bool ans = solve(i, j+1, n, m); //right move
    if(ans){
        return true;
    }
    else{
        bool ans2 = solve(i+1, j, n, m); //down move
        if(ans2){
            return true;
        }
        else {
            board[i][j] = 0;
            return false;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            board[i][j] = 0;
        }
    }

    bool ans = solve(0,0, n, m);

    if(ans){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"-1";
}
