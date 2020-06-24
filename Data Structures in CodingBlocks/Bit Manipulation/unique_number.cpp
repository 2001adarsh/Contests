#include <iostream>
using namespace std;
//when every number occurs twice except one number. Find that number.

int main() {
    int arr[] = {3,2,3,5,6,5,2};
    int ans =0;
    for(int i=0; i<7; i++){
        ans ^= arr[i];
    }
    cout<<ans;
}
