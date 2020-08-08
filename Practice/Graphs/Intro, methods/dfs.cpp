#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    //adj list
    map<T, list<T> > l;
    map<T, bool> visited; // visited array
public:
    void addEdges(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(T node){
        cout<<node<<" ";
        visited[node] = true;
        for(auto nbr: l[node]){
            if(!visited[nbr]){
                dfs(nbr);
            }
        }
    }
};
int main() {
    Graph<int> g;
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(3, 4);
    g.addEdges(2, 5);
    g.addEdges(5,4);

    g.dfs(1);
}
