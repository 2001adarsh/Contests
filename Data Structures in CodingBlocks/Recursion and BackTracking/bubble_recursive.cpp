#include <bits/stdc++.h>
using namespace std;

void bubble(int a[], int n) {
    //base case
    if(n == 1)
        return ;
    //recursive case
    for(int j=0; j<n-1; j++) {
        if(a[j] > a[j+1]){
            swap(a[j], a[j+1]);
        }
    }
    return bubble(a, n-1);
}

void bubble_recursive(int a[], int j, int n) {
    //base case
    if(n == 1) {
        return;
    }
    if(j == n-1) {
        return bubble_recursive(a, 0, n-1);
    }
    //recursive case
    if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
    return bubble_recursive(a, j+1, n);
} 


int main() {
    int arr[] = {5,21,3,5,4};
    //bubble(arr, 5);
    bubble_recursive(arr, 0, 5);
    for(auto it : arr) {
        cout<<it<<" ";
    }

}
