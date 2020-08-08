#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int s, int e, int *tree, int idx){
    //base case
    if(s==e){
        tree[idx] = arr[s];
        return;
    }
    //recursive case
    int mid = (s+e)/2;
    buildTree(arr, s, mid, tree, 2*idx);
    buildTree(arr, mid+1, e, tree, 2*idx+1);
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    return;
}

void updateRange(int *tree, int idx, int ss, int se, int qs, int qe){
    //base case
    //range is not included
    if(ss>qe || qs>se){
        return;
    }
    if(ss == se ){ //if element is in the range, increase it by 10
        tree[idx] += 10; 
        return;
    }
    //recursive case
    //when partial matching happens
    int mid = (ss+se)/2;
    updateRange(tree, 2*idx, ss, mid, qs, qe);
    updateRange(tree, 2*idx+1, mid+1, se, qs, qe);
    tree[idx] = min(tree[2*idx] , tree[2*idx+1]);
    return;
}

int main() {

    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(int);
    int *tree = new int[4*n+1];

    buildTree(arr, 0, n-1, tree, 1);
    
    //printSegment tree
    for(int i=1; i<15; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    //update it by range-> add 10 to all elements from 0..3 in arr
    updateRange(tree, 1, 0, n-1,0,3);

    //printSegment tree
    for(int i=1; i<15; i++){
        cout<<tree[i]<<" ";
    }

}
