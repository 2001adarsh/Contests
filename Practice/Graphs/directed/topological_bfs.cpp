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
    void topological(){
        int *indegree = new int[V];
        for(int i=0; i<V; i++){
            indegree[i] = 0; //initialising indegree to 0.
        }
        //calculate actual indegree
        for(int i=0; i<V; i++){
            for(auto nbr : l[i]){
                indegree[nbr]++;
            }
        }

        queue<int> q; //initialising q for bfs.
        //adding values to queue
        for(int i=0; i<V; i++)
            if(indegree[i] == 0) // Since Topological sorting is done only on DAG
                q.push(i);

        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

};
int main() {
    Graph g(6);
    g.addEdges(0, 2);
    g.addEdges(1,2);
    g.addEdges(2,5);
    g.addEdges(2,3);
    g.addEdges(3,5);
    g.addEdges(4,5);
    g.addEdges(1,4);

    g.topological();
}
