#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int, list<int> > l;
    public:
    void addEdges(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    //finding dfs of 1 connected component
    void dfs_helper(int node, map<int, bool>& visited){
        visited[node] = true;
        cout<<node<<", ";
        for(auto nbr: l[node]){
            if(!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }

    //to calculate all the connected graph
    void dfs(){
        int connected = 0;
        map<int, bool> visited;

        for(auto p: l){
            visited[p.first] = false;
        }

        //checking for all nodes.
        for(auto p: l){
            if(!visited[p.first]){
                connected++;
                cout<<connected<<" ---> ";
                dfs_helper(p.first, visited);
                cout<<endl;
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(1,3);
    g.addEdges(3,4);
    g.addEdges(4,5);
    g.addEdges(3,5);
    g.addEdges(6,7);
    g.addEdges(7,8);

    g.dfs();
}
