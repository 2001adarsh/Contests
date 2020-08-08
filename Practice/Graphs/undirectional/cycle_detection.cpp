#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int, list<int>> l;
public: 
    map<int, bool> visited;
    map<int, int> parent;
    Graph(int V){
        this->V = V;
        for(int i=0; i<V; i++){
            visited[i] = false;
        }
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool detectCycle(int node){
        visited[node] = true;
        for(auto nbr: l[node]){
            if(!visited[nbr]){
                parent[nbr] = node;
                bool ans = detectCycle(nbr);
                return ans;
            }
            else if(visited[nbr] && parent[node]!=nbr){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(4,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    // g.addEdge(0,4);

    cout<<g.detectCycle(0)<<endl;

    for(auto nbr_pair: g.parent){
        cout<<nbr_pair.first<<" ---> "<<nbr_pair.second<<endl;
    }
}
