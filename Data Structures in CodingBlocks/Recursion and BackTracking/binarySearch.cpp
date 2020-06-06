#include <iostream>
using namespace std;

int binary_search(int arr[],int x,int l, int r){
    //base case
    if(l>r){
        return -1;
    }

    int mid = l + (r-l)/2;
    if(x == arr[mid]){
        return mid;
    }
    else if(x > arr[mid]) {
        return binary_search(arr, x, mid+1, r);
    } else{
        return binary_search(arr, x, l, mid-1);
    }
    return -1;
}

//Multiplying two numbers without star
int multi_wo_star(int a, int b){
    //base case
    if(b==0)
        return 0;
    //recursive case
    return a + multi_wo_star(a, b-1);
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    cout<<"Index at:"<<binary_search(arr, 1, 0, 5)<<endl;
    cout<<multi_wo_star(5,3)<<endl;
}
