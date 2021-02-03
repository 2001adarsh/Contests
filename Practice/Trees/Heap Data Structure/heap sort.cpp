#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
//HeapSort -> O(NlogN)

//we have to build the maximum binary heap. then remove the maximum element,
//and place it at last point in the array and heapify for the 0th pos, until the
//size becomes 1.

//max heap
class Heap
{
public:
    int *array;
    int count;
    int capacity;
};

void heapify(Heap *h, int i) {
    int leftChild = (2 * i + 1);
    int rightChild = (2 * i + 2);
    int mx = i;
    if (leftChild < h->count and leftChild >= 0 and h->array[mx] < h->array[leftChild])
        mx = leftChild;
    if (rightChild < h->count and rightChild >= 0 and h->array[mx] < h->array[rightChild])
        mx = rightChild;
    if (mx != i) {
        swap(h->array[i] , h->array[mx]);
        heapify(h, mx);
    }
}

//this can be build by inputing single element at a time, like we did in ADT.
void BuildHeap(Heap* h, int A[], int n) {
    h->count = n;
    for (int i = 0; i < h->count; i++)
        h->array[i] = A[i];
    //since leaf nodes are already heapified, the first not leaf node will be parent
    //of last node. Hence we should heapify from this node.
    for (int i = (h->count - 1) / 2; i >= 0; i--)
        heapify(h, i);
}

void heapSort(int A[], int n) {
    Heap* h = new Heap();
    h->capacity = n;
    h->array = new int[h->capacity];
    h->count = 0;

    BuildHeap(h, A, n);

    for (int i = n - 1; i > 0; i--) {
        swap(h->array[0], h->array[h->count - 1]);
        h->count--;
        heapify(h, 0);
    }

    //coping the array in to original array.
    for (int i = 0; i < n; i++)
        A[i] = h->array[i];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //unsorted array.
    int arr[] = {3, 2, 1, 5, 3, 56, 3, 0};
    int n = sizeof(arr) / sizeof(int);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}