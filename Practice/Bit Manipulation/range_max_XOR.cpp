#include <iostream>
using namespace std;
#define ll long long
// Little girl and Maximum XOR - Codeforces.
// You are given two integers l and r. Let's consider the values of  for
// all pairs of integers a and b (l ≤ a ≤ b ≤ r). Your task is to find the maximum
//  value among all considered ones.

//Find those maximum values xor elements x and y;

int main() {
    ll a,b;
    cin>>a>>b;
 
    int binaryNumA[65] = {0}; 
    int i = 0; 
    while (a > 0) { 
        binaryNumA[i] = a % 2; 
        a = a / 2; 
        i++; 
    } 
  
    // for (int j = 31; j >= 0; j--) 
    //     cout << binaryNumA[j];

    int binaryNumB[65] = {0};
    i = 0;
    while(b > 0){
        binaryNumB[i] = b%2;
        b=b/2;
        i++;
    }
    // cout<<endl;
    // for(int j= 31; j>=0; j--){
    //     cout<<binaryNumB[j];
    // }
    int ans[65] = {0};
    bool flag = false;
    for(int j= 64; j>=0; j--){
        if(binaryNumA[j] == binaryNumB[j] && !flag){
            ans[j] = 0;
        }else if(binaryNumA[j] == binaryNumB[j] && flag){
            ans[j] = 1;
        }else{ 
          ans[j] =1; flag = true;
        }
    }

    int maxX[65] ={0}; //values of maxX and maxY represents the values which gives
    int maxY[65] = {0}; //heightest xor
    flag = false;
    for(int j=64; j>=0; j--){
        if(binaryNumA[j] == binaryNumB[j] && !flag){ //simply copy till first different element
            maxX[j] = binaryNumA[j];
            maxY[j] = binaryNumB[j];
        }else if(binaryNumA[j] == binaryNumB[j] && flag){
            maxX[j] = 1;
            maxY[j] = 1;
        }else{  //else they are not equal and hence can be simply copied
            maxX[j] = binaryNumA[j];
            maxY[j] = binaryNumB[j];
            flag = true;
        }
    }


    cout<<endl;
    for(int j=31; j>=0; j--){
        cout<<maxX[j];
    cout<<endl;
    for(int j=31; j>=0; j--){
        cout<<maxY[j];
    cout<<endl;

    ll result = 0; 
    
    ll p = 1;
    for(int j=31; j>=0; j--){
        cout<<ans[j];   
    }
    cout<<endl;

    for(int i=0; i<65; i++){
        result += ans[i] * p;
        p *= 2; 
    }
    cout<<result;

}
