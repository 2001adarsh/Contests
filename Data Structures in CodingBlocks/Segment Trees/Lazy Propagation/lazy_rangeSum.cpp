#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int s, int e, int *tree, int ind){
    //base case
    if(s == e){
        tree[ind] = arr[s];
        return;
    }
    //recursive case
    int mid = s+ (e-s)/2;
    buildTree(arr, s, mid, tree, 2*ind);
    buildTree(arr, mid+1, e, tree, 2*ind+1);
    tree[ind] = tree[2*ind] + tree[2*ind+1];
    return;
}

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int s, int e, int qs, int qe, int inc, int ind){
    //resolve if any lazy value is there
    if(lazy[ind] != 0){
        tree[ind] += lazy[ind]*(e-s+1); //multiplication because in sum, we actually add 10(inc), a number of times of its range
        if(s!=e){
            lazy[2*ind] += lazy[ind];
            lazy[2*ind+1] += lazy[ind];
        }
        lazy[ind] = 0; 
    }
    //base case
    //no overlap
    if(s>qe || e<qs){
        return;
    }
    //complete overlap
    if(s>=qs && e<=qe){
        tree[ind] += inc*(e-s+1);
        if(s!=e){ //means it has child
            lazy[2*ind] += inc;
            lazy[2*ind+1] += inc; 
        }
        return;
    }
    //recursive case - partial overlap
    int mid = s + (e-s)/2;
    updateRangeLazy(tree, s, mid, qs, qe, inc, 2*ind);
    updateRangeLazy(tree, mid+1, e, qs, qe, inc, 2*ind+1);
    tree[ind] = tree[2*ind] + tree[2*ind+1];
    return;
}

int queryRangeLazy(int *tree, int s, int e, int qs, int qe, int ind){
    //Resolve lazy first
    if(lazy[ind] != 0){
        tree[ind] += lazy[ind]*(e-s+1);
        if(s!=e){ //further children
            lazy[2*ind] += lazy[ind];
            lazy[2*ind+1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    //base case
    //no overlapping
    if(s>qe || e<qs){
        return 0;
    }
    //complete overlapping
    if(s>=qs && e<=qe){
        return tree[ind];
    }
    //recursive case - partial overlapping
    int mid = s + (e-s)/2;
    int left = queryRangeLazy(tree, s, mid, qs, qe, 2*ind);
    int right = queryRangeLazy(tree, mid+1, e, qs, qe, 2*ind+1);
    return left+right;
}

int main() {
    int arr[] = {1, 2, 2, 3, 0, 4, 3, 6, 9, 10};
    int n = sizeof(arr)/sizeof(int);

    int *tree = new int[4*n+1];

    buildTree(arr, 0, n-1, tree, 1);

    //segment tree
    for(int i=1; i<(4*n); i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    updateRangeLazy(tree, 0, n-1, 0, 2, 10, 1);

    //segment tree showing the difference only till 0..2
    for(int i=1; i<(4*n); i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Q1 -> 1-2 : "<<queryRangeLazy(tree, 0, n-1, 1, 2, 1)<<endl;

}
