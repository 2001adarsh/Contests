#include <bits/stdc++.h>
using namespace std;
const int N=100005, M =22;

//Barpitite Graph is a graph which can be divided into two sets such that ends of one edge doesn't lie in same set
// It is also called 2 color graph. where adjacent nodes dont have same color.
vector<int> gr[N];
int vis[N]; //visited array will have 3 states - 0 for not visited, 1- color, 2- other color
bool isBipartite = true;

void dfs(int node, int parent, int color){
    vis[node] = color;
    for(auto child : gr[node]){
        if(!vis[child]){
            dfs(child, node, 3-color); //will pass 2 when node color is 1 and viceversa       
        }else if(child != parent && color == vis[child]){
            //if there is a odd cycle, it cannot be bipartite graph
            isBipartite = false;
        }
    }
    return;
}

int main() {
    int n,m, ans =0;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    dfs(1, 0, 1); //passing current node and a parent with initial color as 1
    if(isBipartite){
        cout<<"Graph is Barpitite graph";
    }else{
        cout<<"Graph is not bipartite graph";
    }
}
