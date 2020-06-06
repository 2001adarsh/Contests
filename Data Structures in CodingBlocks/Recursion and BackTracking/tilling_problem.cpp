#include <bits/stdc++.h>
using namespace std;
/*
int tilling_ways(int n) {
    //base case
   if(n==1 || n<=4)
        return 1;
    if(n<=0)
        return 0;
    //recursive case
   return tilling_ways(n-1) + tilling_ways(n-4);
}
*/
string digits[] = {"zero", "one", "two", "three", "four", 
"five", "six", "seven", "eight", "nine"};
void printNum(int n){
    //base case
    if(n == 0){
        return;
    }
    //recursive case
    printNum(n/10);
    cout<<digits[n%10]<<" ";
}

int main() {
    //cout<<"Tilling ways:"<<tilling_ways(4)<<endl;
    printNum(2048);
    return 0;
}
