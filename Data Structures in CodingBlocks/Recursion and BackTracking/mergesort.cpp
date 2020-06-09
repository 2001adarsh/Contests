#include <iostream>
using namespace std;

void merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int n = mid, m = e;
    int i=s, j=n+1, k=s;
    int temp[100];
    while(i<=n && j<=m) {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else 
            temp[k++] = a[j++];
    }
    while(i<=n)
        temp[k++] = a[i++];
    while(j<=m)
        temp[k++] = a[j++];
    
    for(int i=s; i<=e; i++)
        a[i] = temp[i];
}

void mergesort(int *a, int s, int e){
    //base case
    if(s>=e)
        return ;
    //recursive case
    int mid = (s+e)/2;
    mergesort(a, s, mid);
    mergesort(a, mid+1, e);
    merge(a,s,e);
}

//Inversion Count
int inversionAdd(int *a, int s, int e){
    int mid = (s+e)/2;
    int n = mid, m=e;
    int i=s, j=n+1, k=s, cnt=0;
    int temp[100];

    while(i<=n && j<=m) {
        if(a[i]<=a[j])
            temp[k++] = a[i++];
        else{
            //cout<<a[i]<<" , "<<a[j]<<endl; //-> showing of the pairs
            temp[k++] = a[j++];
            cnt += n -i +1;
        }
    }
    while(i<=n){
        temp[k++]= a[i++];
    }
    while(j<=m){
        temp[k++] = a[j++];
    }
    //converting array back
    for(int i=s; i<=e; i++)
        a[i] = temp[i];

    return cnt;
}

int inversionCount(int *a, int s, int e){
    //base case
    if(s>=e){
        return  0;
    }
    //recursive case
    int mid = (s+e)/2;
    int x = inversionCount(a,s, mid);
    int y = inversionCount(a, mid+1, e);
    int z = inversionAdd(a, s, e);
    return x+y+z;
}

int main() {
    int a[] = {5,2,3,1,5};
    mergesort(a, 0, 4);
    for(auto i:a){
        cout<<i<<" ,";
    }   cout<<endl;

    //Inversion Count ->checks for i!=j, a[i] > a[j] in an array.
    //Can also be called as how much nearly sorted.
    int arr[] = {1,5,2,6,3,0};
    cout<<inversionCount(arr,0, 5)<<endl;
}
