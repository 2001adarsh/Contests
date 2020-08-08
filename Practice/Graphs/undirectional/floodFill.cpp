#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1 , 0, 1 , 0};
int dy[] = {0, -1, 0, 1};

// ch - ch is the character to be replaced
// color - is the character to be added
void floodFill(int mat[][50], int i, int j, int ch, int color){
    if(i<0 || j<0 || i>=R || j>=C)  //matrix bound
        return;
    if(mat[i][j] != ch) //figure bound
        return;
    mat[i][j] = color;
    for(k=0; k<4; k++){
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    } 
}

int main() {
    cout<<"Hello World!";
}
