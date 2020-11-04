#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// Network Flow in Graphs.
/*

Each edge is considered as a pipe, with maximum capacity as weight.
The flow is the amount which can flow from the pipe without exceeding the capacity.
Hence, there is a source(Producer) and a sink(consumer).
Find the maximum flow from source to sink.

Terminologies:

Capacity -> flow is the exact amount of the material flowing through the edge, whereas
capacity is the maximum amount of material that can flow through that edge.
Flow can never be more than capacity.

Residual capacity -> the difference of the total capacity and the flow of the material

Residual Graph -> if the given graph is represented in terms of residual capacity.

Augmented Path -> the path from source(S) to sink(T) such that the residual capacity on every
        stage is > 0.
Maximum flow will be the edge with the minimum capacity in the path.


Hence we use an algorithm -> Ford Fulkerson Algorithm to calculate the maximum Flow in a given
network flow graph.

*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    return 0;
}