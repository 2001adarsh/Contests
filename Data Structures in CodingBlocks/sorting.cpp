#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& a, int l, int r){
    int x = a[l];
    int j=l;
    for(int i=l+1; i<=r; i++){
        if(x >= a[i]){
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j],a[l]);
    return j;
}

void quicksort(vector<int>& arr, int l, int r){
    if(l>=r){
        return ;
    }
    int mid = Partition(arr, l, r);
    quicksort(arr, l, mid-1);
    quicksort(arr, mid+1, r);
}

vector<int> merge(vector<int> a, vector<int> b){
    int i=0, j=0;
    vector<int> result;
    while(i<a.size() && j<b.size()){
        if(a[i] <= b[j]){
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    //If some elements still left
    while(i<a.size()){
        result.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        result.push_back(b[j]);
        j++;
    }
    return result;
}

vector<int> mergesort(vector<int>& arr){
    if(arr.size() == 1)
        return arr;

    int mid = (int)(arr.size()-1)/2;
    vector<int> b(arr.begin(), arr.begin()+mid+1);
    b = mergesort(b);
    vector<int> c(arr.begin()+mid+1, arr.begin()+arr.size());
    c = mergesort(c);

    return merge(b,c);
}

//Faster quick sort for equal numbers

void partition3(vector<int>&a, int l, int r, int& i, int&j) {
    int x = a[l];
    i = l, j = l;
    for(int k=l+1; k<=r; k++) {
        if(a[k] == x){
            j++;
            swap(a[j], a[k]);
        }
        if(a[k] < x){
            i++;   j++;
            swap(a[i], a[k]);
            if(a[k] == x){
                swap(a[j], a[k]);
            }
        }
    }
    swap(a[i], a[l]);
}
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
    int i,j;
    partition3(a,l,r, i,j);

  randomized_quick_sort(a, l, i);
  randomized_quick_sort(a, j+1, r);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, arr.size()-1);
    vector<int> res =  mergesort(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
