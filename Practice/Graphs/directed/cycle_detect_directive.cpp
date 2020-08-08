#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdges(int x, int y){
        l[x].push_back(y);
    }

    bool cycle_helper(int node, bool* vis, bool* recurStack){
        vis[node] = true;
        recurStack[node] = true;

        for(auto nbr: l[node]){
            if(recurStack[nbr]){
                return true;
            }else if(!vis[nbr]){
                bool ans = cycle_helper(nbr, vis, recurStack);
                if(ans == true)
                    return true;
            }
        }
        return false;
    }

    bool cycle_detect(){
        bool *vis = new bool[V+1];
        bool *recurStack = new bool[V+1];
        //initialisation to false
        for(int i=0; i<V; i++){
            vis[i] = false;
            recurStack[i] = false;
        }
        bool ans = false;
        for(int i=0; i<V; i++){
            if(!vis[i])
            {
                bool g = cycle_helper(i, vis, recurStack);
                if(g){
                    ans = true;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(7);
    g.addEdges(0,1);
    g.addEdges(1,5);
    g.addEdges(5,6);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(4,2);
    g.addEdges(4,5);

    cout<<g.cycle_detect();
}
