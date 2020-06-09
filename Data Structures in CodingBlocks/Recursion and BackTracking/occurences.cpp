#include <iostream>
using namespace std;
int linear(int arr[], int n, int key){
    //base case
    if(n == 0)
        return -1;    
    //recursive case
    if(arr[0] == key)
        return 0;
    return linear(arr+1, n-1, key) + 1;
}

int lastOcc(int arr[], int n, int key){
    //base case
    if(n==0)
        return -1;
    //recursive case
    int ccase = lastOcc(arr+1, n-1, key);
    if(ccase ==-1 && arr[0] != key)
        return -1;
    return ccase+1;
}

void allOcc(int arr[], int n, int i, int key){
    //base case
    if(i==n){
        return;
    }
    //recursive case
    if(arr[i] == key)
        cout<<key<<" is at: "<<i<<endl;
    allOcc(arr, n, i+1, key);
}

int storeOcc(int *arr, int n, int i, int key, int *output, int j){
    //base case
    if(i == n)
        return j;
    //recursive case
    if(arr[i] == key) {
        output[j] = i;
        j = j+1;
    }
    return storeOcc(arr, n, i+1, key, output, j);
}

int main() {
 int arr[] = {5,2,4,2,1};
 int atIndex = linear(arr,5,1);
 cout<<atIndex<<endl;
 cout<<lastOcc(arr, 5, 12)<<endl;
 allOcc(arr, 5, 0, 2);

 int output[100];
 cout<<"Size of output: "<<storeOcc(arr, 5, 0, 2, output, 0);
}
