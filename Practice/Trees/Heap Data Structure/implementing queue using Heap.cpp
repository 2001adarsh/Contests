#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Building queue using Heaps (priority queue).
class Queue
{
public:
    priority_queue<pair<int, int> > pq;
    int c = 0; //this is used as priority during insertion/deletion.
    Queue() {
        c = 0;
    }
    void push(int data) {
        --c;
        pq.push({c, data});
    }
    void pop() {
        if (!pq.empty())
            pq.pop();
    }
    int front() {
        if (pq.empty()) return -1;
        return pq.top().second;
    }
    bool isEmpty() {
        return pq.empty();
    }
};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Queue qu = Queue();
    qu.push(5);
    qu.push(3);
    qu.pop(); //removes the front - 5.
    qu.push(6);
    qu.push(7);
    //queue data.
    while (!qu.isEmpty()) {
        cout << qu.front();
        qu.pop();
    }

    return 0;
}