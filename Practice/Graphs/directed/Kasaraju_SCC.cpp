#include <bits/stdc++.h>
using namespace std;

//Kasaraju's algorithm for Strongly Connected Component in Directed Graphs.
//Means if any vertex x->y and y->x then they are in same component.

const int N = 100005;
vector<int> gr[N], rgr[N];
vector<int> post_order;
vector<int> component[N];
int vis[N];

void dfs(int node){
    vis[node] = 1;
    for(auto nbr: gr[node])
        if(!vis[nbr]) dfs(nbr);

    post_order.push_back(node);
}

void dfs_reverse(int node, int color){
    vis[node] = 1;
    component[color].push_back(node); //will accumulate all same component in one 
    for(auto nbr: rgr[node])
        if(!vis[nbr]) dfs_reverse(nbr, color);
}

void solve(){
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        gr[x].push_back(y);
        rgr[y].push_back(x); //reverse graph 
    }

    //taking order of all node in given graph
    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i);
    
    //again mark visited as 0
    memset(vis, 0, sizeof(vis));
    int comp =0; //count of component
    for(int i=n; i>=1; i--){
        if(!vis[post_order[i-1]]){ //calculating with last order(max) 
            comp++;
            dfs_reverse(post_order[i-1], comp); //dfs for reverse graph
        }
    }
    cout<<comp<<endl; //no. of strongly connected components.
    for(int i=1; i<=comp; i++)
    {
        for(auto x: component[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main() {
    solve();
}
