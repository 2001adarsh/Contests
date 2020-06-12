#include <iostream>
using namespace std;

// Prints all ACODE which can be formed with integers. Like 1 as A, 2 as B, 26 as Z. So all kinds of those.

void permute(string original, int i, string output) {
    //base case
    if(i == original.size()){
        cout<<output<<endl;
        return;
    }
    //recursive case
    //Either it will take 1 character as input or
    int digit = original[i] - '0';
    char value = digit + 'A';
    
    permute(original, i+1, output+value);
    //take two character if value is less than 26 
    
    if(i != original.size()-1){  //if last element, pair cannot be formed.
        digit = original[i] - '0';
        int digit1 = original[i+1] - '0';
        digit = digit*10 + digit1;
        if(digit <= 26){
             value = digit + 'A'-1;
             permute(original, i+2,output+value);
        }
    }  
 }

int main() {
    permute("1234", 0, "");
}
