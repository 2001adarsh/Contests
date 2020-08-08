// We are given an array containg n numbers. 
//All the numbers are present thrice except for one 
//number which is only present once. Find the unique number. 
//Only use - bitwise operators, and no extra space.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, no;
    cin>>n;
    int cnt[64] = {0};

    for(int i=0; i<n; i++){
        cin>>no;
        int j=0;
        while(no > 0) {
            cnt[j] += no&1;
            j++;
            no = no>>1; 
        }
    }
    //Since here the result is in form of either 3N or 3N+1.
    //because there are numbers with either 3 times and one no. with just 1 time.
   
    //Update the array and compute the result
    int p = 0; //power of 2.
    int result =0; //ans
    for(int i=0; i<64; i++){
        cnt[i] %= 3;  //to have array only of 0 and 1.
        result += cnt[i]*pow(2,p);
        p++;
    } 
    cout<<result;
}

