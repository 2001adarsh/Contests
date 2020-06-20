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

void pointUpdate(int *tree, int ind, int s, int e, int update){
    //base case
    if(s==e && s==update){ //if update range found
        tree[ind] += 10; //updating by inc 10, can also pass value which have to be updated.
        return; 
    }
    if(!(update>=s && update<=e)){ //if update index not in range
        return;
    }
    //recursive case
    int mid = (s+e)/2;
    pointUpdate(tree, 2*ind, s, mid, update);
    pointUpdate(tree, 2*ind+1, mid+1, e, update);
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
    return; 
}

int main() {
    int arr[] = { 1, 3, 2, -5, 6, 4};
    int n = sizeof(arr)/sizeof(int);
    
    int *tree = new int[4*n+1];
    buildTree(arr, 0, n-1, tree, 1);

    //Segment Tree
    for(int i=1; i<14; i++){
        cout<<tree[i]<<" ";
    }

    cout<<endl<<"The Min value in "<<endl;
    //find min value in range 0..5
    cout<<"0..5: "<<minFind(tree, 1, 0, n-1, 0, 5)<<endl;
    cout<<"2..4: "<<minFind(tree, 1, 0, n-1, 2, 4)<<endl;
    cout<<"4..4: "<<minFind(tree, 1, 0, n-1, 4, 4)<<endl;

    //Point Updates:
    //Update any value in arr.
    pointUpdate(tree, 1, 0, n-1, 3);


    //Segment Tree
    for(int i=1; i<14; i++){
        cout<<tree[i]<<" ";
    }
    
    cout<<endl<<"The Min value in "<<endl;
    //find min value in range 0..5
    cout<<"0..5: "<<minFind(tree, 1, 0, n-1, 0, 5)<<endl;
    cout<<"2..4: "<<minFind(tree, 1, 0, n-1, 2, 4)<<endl;
    cout<<"4..4: "<<minFind(tree, 1, 0, n-1, 4, 4)<<endl;

}
