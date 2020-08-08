#include <iostream>
using namespace std;

//Rat in a Maze problem.
//printing numbers of solutions


int ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n, int count){
    //base case
    if(i==m && j==n){
        soln[m][n] = 1;
        //print result;
        for(int k=0; k<=m; k++){
            for(int l=0; l<=n; l++)
            {
                cout<<soln[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return count+1;
    }
    //recursive case

    if(i>m || j>n) { //inside the grid
        return count;
    }
    if(maze[i][j] == 'X')  //Dead end
        return count;
    
    //Assume solution exits
    soln[i][j] = 1;
    int right =0, down= 0;
    right += ratInMaze(maze, soln, i, j+1, m,n, count);
    down += ratInMaze(maze, soln, i+1, j, m,n, count);
    
    //Backtracking
    soln[i][j] = 0;
    return right+down;
}

int main() {
    char maze[10][10] = {
            "0000",
            "00X0",
            "000X",
            "0X00"
    };

    int soln[10][10] ={0};

    int ans = ratInMaze(maze, soln, 0, 0, 3,3,0);
    cout<<ans;
}
