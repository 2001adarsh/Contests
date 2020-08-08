/*
    Segment Trees are used generally in a Range-Based Queries.
    uses divide and conquer method

    The root node contains info for (0-n) and then subsequently
    divides itself in two parts for the left(0-mid) and right(mid+1, n)
    and recursively fills up the tree.

    Max Size of tree would be -> 4*N +1
    else -> smallest power of 2 just greater than N.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int s, int e, int *tree, int ind){
    //base case
    if(s == e)
    {
        tree[ind] = arr[s];
        return;
    }
    //recursive case
    int mid = (s+e)/2;
    buildTree(arr, s, mid, tree, 2*ind );
    buildTree(arr, mid+1, e, tree, 2*ind+1);
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
    return;
}

int minFind(int *tree, int ind, int s, int e, int qs, int qe){
    //base case
    //if(complete overlapping)
    if( s>=qs && e<=qe ){
        return tree[ind];
    }
    //if(no overlapping)
    if(e<qs || qe<s){ 
        return INT_MAX;
    }
    //recursive case
    //if partial overlaping
    int mid = (s+e)/2;
    int a = minFind(tree, 2*ind, s, mid, qs, qe); //left 
    int b = minFind(tree, 2*ind+1, mid+1, e, qs, qe);   //right
    return min(a,b);
}

int main() {
    int arr[] = { 1, 3, 2, -5, 6, 4};
    int n = sizeof(arr)/sizeof(int);
    
    int *tree = new int[4*n+1];
    buildTree(arr, 0, n-1, tree, 1);

    for(int i=1; i<14; i++){
        cout<<tree[i]<<" ";
    }

    cout<<endl<<"The Min value in "<<endl;
    //find min value in range 0..5
    cout<<"0..5: "<<minFind(tree, 1, 0, n-1, 0, 5)<<endl;
    cout<<"2..4: "<<minFind(tree, 1, 0, n-1, 2, 4)<<endl;
    cout<<"4..4: "<<minFind(tree, 1, 0, n-1, 4, 4)<<endl;

}
