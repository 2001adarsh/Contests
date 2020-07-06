#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> gr[N];

void bfs(int src,int n, int& ans){
    vector<int> dist(n+1, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto nbr: gr[node]){
            if(dist[nbr] == INT_MAX){
                dist[nbr] = dist[node]+1;
                q.push(nbr);
            }else if(dist[nbr] >= dist[node]){
                //it is already been visited 
                //dist[node] + dist[nbr]  +1 will give length of this circle
                ans = min(ans, dist[node]+dist[nbr]+1);
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int ans =n+1;
    for(int i=1; i<=n;i++){
        bfs(i, n, ans);
    }
    cout<<ans<<endl;
}
