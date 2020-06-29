#include <bits/stdc++.h>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int s, int e, int qs, int qe, int inc, int index){
    //update before going down to resolve the value if exist
    if(lazy[index] != 0){
        tree[index] += lazy[index]; //update this point
        if(s!=e){ //has a child below
            lazy[2*index] += lazy[index];  //updating lazy value of child.
            lazy[2*index+1] += lazy[index]; 
        }
        lazy[index] = 0; //this point lazy value to zero
    }

    //base case
    //no overlap
    if(e<qs || s>qe){
        return;
    }
    //complete overlap
    if(s>=qs && e<=qe){
        tree[index] += inc;
        if(s!=e){ //means it has a child below
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return;
    }
    //recursive case - partial overlap
    int mid = s + (e-s)/2;
    updateRangeLazy(tree, s, mid, qs, qe, inc, 2*index);
    updateRangeLazy(tree, mid+1, e, qs, qe, inc, 2*index+1);
    //update the tree while going back up
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int queryLazy(int *tree, int s, int e, int qs, int qe, int index){
    //Resolve lazy value if any
    if(lazy[index] != 0){
        tree[index] += lazy[index];
        if(s != e) { //it has child further
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0; //making this lazy value to zero as we added it in tree
    }
    //base case
    //no overlap
    if(s>qe || e<qs){
        return INT_MAX;
    }
    //complete overlap
    if(s>=qs && e<=qe){
        return tree[index]; //In queries we are not handling lazy updation here because it is being handled in the first case and we dont care about the below terms now.
    }
    //recursive case - partial overlap
    int mid = s+ (e-s)/2;
    int left = queryLazy(tree, s, mid, qs, qe, 2*index);
    int right = queryLazy(tree, mid+1, e,  qs, qe, 2*index+1);
    return min(left, right);
}

void buildTree(int *arr, int s, int e, int *tree, int ind){
    //base case
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    //recursive case
    int mid = s+ (e-s)/2;
    buildTree(arr, s, mid, tree, 2*ind);
    buildTree(arr, mid+1, e, tree, 2*ind+1);
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
    return;
}

int main() {
    int arr[] = {1,3,2,-5, 6,4};
    int n = sizeof(arr)/sizeof(int);
    int *tree = new int[4*n+1];

    buildTree(arr, 0, n-1, tree, 1);

    //segment tree
    for(int i=1; i<15; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    updateRangeLazy(tree, 0, n-1, 0, 2, 10, 1); //update 0..2 by incrementing 10.
    updateRangeLazy(tree, 0, n-1, 0, 4, 10, 1); //update 0..4 by inc 10
    cout<<"Q1 -> 1-1 : "<<queryLazy(tree, 0, n-1, 1, 1, 1)<<endl;
    updateRangeLazy(tree, 0, n-1, 3, 4, 10, 1);
    cout<<"Q2 -> 3-5 : "<<queryLazy(tree, 0, n-1, 3, 5, 1)<<endl;
}
