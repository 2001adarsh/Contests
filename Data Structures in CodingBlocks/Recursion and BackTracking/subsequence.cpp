#include <iostream>
using namespace std;

void subsequence(string input,int i, string output,int j) {
    //base case
    if(i == input.size() || j == input.size()){
        cout<<output<<endl;
        return;
    }
    //recursive case
    subsequence(input, i+1, output+input[i], j+1);
    subsequence(input, i+1, output, j);
}

int main() {
    subsequence("abc", 0, "", 0);
}
