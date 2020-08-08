#include <iostream>
#include <algorithm>
using namespace std;

int arrange(int *a, int s, int e){
    int key = a[e]; //taking pivot to be last element
    int i=s, j=s;
    for(int j=s; j<e; j++){
        if(a[j] <= key) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[e]);
    return i;
}

void quicksort(int *a, int s, int e){
    //base case
    if(s>=e)
        return;
    int mid = arrange(a, s, e);
    quicksort(a, s, mid-1);
    quicksort(a, mid+1, e);
}

int main() {
    int arr[] ={1,5,2,6,3,0,4};
    quicksort(arr, 0, 6);
    for(auto i: arr)
        cout<<i<<" ";
}
