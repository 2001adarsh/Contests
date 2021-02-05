#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Building stack using Heaps (priority queue).
class Stack
{
public:
    priority_queue<pair<int, int> > pq;
    int c = 0; //this is used as priority during insertion/deletion.
    Stack() {
        c = 0;
    }
    void push(int data) {
        ++c;
        pq.push({c, data});
    }
    void pop() {
        if (!pq.empty())
            pq.pop();
    }
    int top() {
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

    Stack st = Stack();
    st.push(5);
    st.push(3);
    st.push(6);
    st.push(3);
    while (!st.isEmpty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}