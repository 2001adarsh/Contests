#include <iostream>
using namespace std;

//Placing N Queens in the grid so that all remain safe from each other.

bool valid(int board[][10], int m, int n, int i, int j){
    //checking row
    for(int k=0; k<n; k++)
        if(board[i][k] == 1)
            return false;
    //checking column
    for(int k=0; k<m; k++)
        if(board[k][j] == 1)
            return false;
    //checking left diagonal upper
    int k=i-1, l=j-1;
    while(k>=0 && l>=0){
        if(board[k][l] == 1)
            return false;
        k--;
        l--;
    }
    //checking right diagonal upper
    k=i-1, l= j+1;
    while(k>=0 && l<n) {
        if(board[k][l] == 1)
            return false;
        k--;
        l++;
    }
    //else it is a valid position
    return true;
}

bool nQueen(int board[][10], int n, int i){
    //base case
    if(i==n){
        for(int k=0; k<n; k++){
            for(int j=0; j<n; j++)
            cout<<board[k][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return false;  // So that flow of recursion doesn't stop. It continues till all values are present

    }
    //recursive case
    for(int j=0;j<n;j++){
        if(valid(board, n, n, i, j)){
            board[i][j] = 1;
            bool nextQueen = nQueen(board, n, i+1);
            if(nextQueen == true){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}


int main() {
    int board[10][10] ={0};
    bool ans = nQueen(board, 4, 0);
}
