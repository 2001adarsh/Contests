#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int, int> > *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int> >[V];
    }

    void addEdge(int x, int y, int cost){
        l[x].push_back(make_pair(y, cost));
        l[y].push_back(make_pair(x, cost));
    }

    int dfs_helper(int node, bool *visited, int *count, int &ans){
        visited[node] = true;
        count[node] = 1;
        //for each node inside
        for(auto nbr_pair: l[node]){
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if(!visited[nbr]){
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }
        return count[node];        
    }

    int dfs(){
        bool *visited = new bool[V];
        int *count = new int[V];

        //marking them initially to false
        for(int i=0; i<V; i++){
            visited[i] = false;
            count[i] = 0;
        }
        int ans =0;
        int x = dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main() {
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       Graph g(n);
       for(int i=0; i<n-1; i++){
           int x, y, w;
           cin>>x>>y>>w;
           x--; y--;
           g.addEdge(x,y,w);
       }
       cout<<g.dfs()<<endl;
   }
}
