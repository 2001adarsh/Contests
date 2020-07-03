#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    //map for storing graph
    map<T, list<T> > l;
public:
    void addEdges(T x, T y){
        l[x].push_back(y);
    }

    //BFS Single source shortest path
    void bfsSSSP(T src, T dest){
        map<T, int> dist; //distance from source
        queue<T> q; //for execution of bfs
        map<T, T> parent; //stores parent of other nodes.

        for(int i=0; i<37; i++){
            dist[i] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            T node= q.front();
            q.pop();
            if(node == dest)
                break;

            for(auto nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    parent[nbr] = node;
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        //printing parents of all nodes
         for(auto i: parent){
             cout<<i.first<<" -> "<<i.second<<endl;
         }

        //printing the path of destination to src
         T node = dest;
         while(node != src){
             cout<<node<<" -> ";
             node = parent[node];
         }

         //can return the maximum dice by
         //return dist[dest];
    }

};


int main() {
    
    Graph<int> g;
      
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //adding edges
    for(int i=0; i<36; i++){
        for(int j=1; j<=6; j++){
            int next = i+j; //current step
            next += board[next];    //adding jump for ladder or snake if any at that position
            if(next < 37){
                g.addEdges(i, next);
            }
        }
    }
    g.addEdges(36,36);
    g.bfsSSSP(0 , 36);
}
