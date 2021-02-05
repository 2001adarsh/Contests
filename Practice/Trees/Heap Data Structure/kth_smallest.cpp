#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// finding kth-smallest element in min-heap.

/*
solution:
1. perform k deletions. - O(KlogN)
*/

//heapify for min-heap.
void heapify(int heap[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int mi = i;
    if (left < n and heap[left] < heap[mi])
        mi = left;
    if (right < n and heap[right] < heap[mi])
        mi = right;
    if (mi != i) {
        swap(heap[i] , heap[mi]);
        heapify(heap, n, mi);
    }
}

void deletions(int heap[], int &n) {
    heap[0] = heap[n - 1];
    n--;
    heapify(heap, n, 0);
}

//performing k deletions.
int kth_smallest1(int heap[], int n, int k) {
    // as 1st min will be top only.
    for (int i = 0; i < k - 1; i++)
        deletions(heap, n);
    return heap[0];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //min-heap.
    int heap[] = {1, 2, 5, 3, 4, 6, 7};
    int n = sizeof(heap) / sizeof(int);

    int k = 5;
    cout << kth_smallest1(heap, n, k);


    return 0;
}