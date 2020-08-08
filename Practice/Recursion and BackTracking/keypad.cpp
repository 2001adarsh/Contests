#include <iostream>
#include <bits/stdc++.h>
using namespace std;
                    //0  1   2      3       4      5      6     7       8       9
string numpad[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

void keypad(string integer, int i, string output) {
    //base case
    if(i==integer.size()) {
        cout<<output<<endl;
        return;
    }
    //recursive case
    int digit = integer[i] - '0';
    if(digit == 1 || digit == 0) { //if 1 or 2 since numpad is empty at this, it will git function return.
        keypad(integer, i+1, output);
    }

    for(int j=0; j<numpad[digit].size(); j++){
        keypad(integer, i+1, output+(numpad[digit][j]));
    }
}

int main() {
    string integer= "666";
    keypad(integer, 0, "");
}
