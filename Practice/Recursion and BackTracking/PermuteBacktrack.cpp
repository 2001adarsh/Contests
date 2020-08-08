#include <iostream>
using namespace std;
//Permutations of a string

void permute(string org, int i) {
    //base case
    if(i == org.size()) {
        cout<<org<<endl;
        return; 
    }
    //recursive case
    for(int j=i; j<org.size(); j++) {
        swap(org[i], org[j]);
        permute(org, i+1);
    }
}


//This function will give wrong answer because arrays are passed
//as refrence, unlike any string,int, etc. Hence changes the value everytime.
//Need for backtracking in these cases.
void Permutations(char *inp, int i) {
    //base case
    if(inp[i] == '\0'){
        cout<<inp<<endl;
        return;
    }
    //recursive case
    for(int j=i; inp[j] != '\0'; j++) {
        swap(inp[i], inp[j]);
        Permutations(inp, i+1);
        swap(inp[i], inp[j]); //backtracking. Neccessary to undo the changes.while going up.
                              //Make recursion call stack for details.
    }
}

int main() {

    permute("abc", 0);
    
    cout<<"-----------"<<endl;
    
    char inp[10] = "abc";
    Permutations(inp, 0);
    
    cout<<"-----------"<<endl;
    
   
}
