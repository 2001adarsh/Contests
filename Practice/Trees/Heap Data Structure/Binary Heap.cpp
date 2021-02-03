#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
//Binary Heap -> Simple implementation.

//Eg-> max heap. Time complexity at last of code.
class Heap
{
public:
    int *array; // array to represent tree.
    int count; //number of nodes in tree.
    int capacity; // total size for allocation.
    // int heap_type; just in case, user has to decide which heap he has to build.
};

// returns parent position of i.
int parent(Heap *h, int i) {
    if (i < 0 or i >= h->count)
        return -1;
    return (i - 1) / 2;
}
//returns child position of i.
int LeftChild(Heap *h, int i) {
    int l = 2 * i + 1;
    if (l < 0 or l >= h->count)
        return -1;
    return l;
}
int RightChild(Heap *h, int i) {
    int r = 2 * i + 2;
    if (r < 0 or r >= h->count)
        return -1;
    return r;
}

//we will start from the bottom, can go till top using parent.
// O(logn);
void insert(Heap* h, int data) {
    // if (h->count == h->capacity) //if array is already full.
    // resize(h);
    h->count++;
    int i = h->count - 1; //last empty position.
    while (i > 0 and data > h->array[(i - 1) / 2]) {
        h->array[i] = h->array[(i - 1) / 2]; // swaping with parent.
        i = (i - 1) / 2; //making i as parent now.
    }
    h->array[i] = data;
}

void heapify(Heap*h, int i) {
    int l = LeftChild(h, i);
    int r = RightChild(h, i);
    int mx = i; //taking i as maximum.
    if (l != -1 and h->array[l] > h->array[mx])
        mx = l;
    if (r != -1 and h->array[r] > h->array[mx])
        mx = r;
    //this means that, the node is not in correct position. So, take
    //the maximum children and swap with node, and heapify for that position.
    if (mx != i) {
        int temp = h->array[i];
        h->array[i] = h->array[mx];
        h->array[mx] = temp;
        heapify(h, mx);
    }
    //otherwise, everything is in right place,stop.
}

// removes the maximum element.
void Delete(Heap* h) {
    if (h->count == 0) return;
    //otherwise, make the last element as first, delete last element,
    // and start heapification from first element.
    h->array[0] = h->array[h->count - 1];
    h->count--;
    heapify(h, 0);
}

// max-element of binary heap
int top(Heap *h) {
    if (h->count == 0)
        return INT_MAX;
    return h->array[0];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //input array.
    int input[] = {1, 5, 2, 6, 3, 8, 0, 6};
    int n = sizeof(input) / sizeof(int);


    Heap* h = new Heap();
    h->array = new int[n];
    h->capacity = n;
    h->count = 0;

    for (int i = 0; i < n; i++) {
        insert(h, input[i]);
    }

    //after inserting all.
    for (int i = 0; i < h->count; i++)
        cout << h->array[i];

    Delete(h);
    Delete(h);
    cout << endl;

    //after deleting two nodes from top.
    for (int i = 0; i < h->count; i++)
        cout << h->array[i];

    //the top element, is the maximum element in binary heap.
    cout << endl << top(h);

    return 0;
}
/*
    Time Complexity:
    insertion and deletion takes O(logN) time.
    max_element() takes O(1) time.

    but these occur when we insert one element at once, so if
    we consider running of input loop it looks like O(NlogN) time
    but heapify takes different time for different values.
    Hence, making build of Heap as O(N).
*/


/*Heap* createHeap(int capacity, int heap_type) {
    Heap* h = new Heap();
    h->array = new int[capacity];
    h->capacity = capacity;
    h->count = 0;
    h->heap_type = heap_type;
    return h;
}*/