#include <bits/stdc++.h>
using namespace std;
//Implementation of Topological Sort using DFS.
template<typename T>
class Graph{
    map<T, list<T> > l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y); //Directed graph
    }

    void dfs_helper(T node, map<T, bool> &visited, list<T> &order){
        visited[node] = true;
        for(auto nbr: l[node]){
            if(!visited[nbr])
                dfs_helper(nbr, visited, order);
        }
        order.push_front(node);
        return;
    }

    void dfs(){
        map<T, bool> visited;
        list<T> order;
        for(auto p: l){ //initialising visited to false.
            T node = p.first;
            visited[node] = false;
        }
        for(auto p: l){
            if(!visited[p.first]){
                dfs_helper(p.first, visited, order);
            }
        }

        //Printing the topological sort.
        for(auto ord : order){
            cout<<ord<<" ";
        }
    } 
};

int main() {
    Graph<char> g;
    g.addEdge('a', 'b');
    g.addEdge('b', 'c');
    g.addEdge('c', 'd');
    g.addEdge('c', 'e');
    g.addEdge('e', 'f');

    g.dfs();
}
