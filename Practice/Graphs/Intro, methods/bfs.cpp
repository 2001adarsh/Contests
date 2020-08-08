#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T> > l; 
public:
    void addEdges(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        map<T, int> visited;
        queue<T> q;
        //first node
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ,";
            for( auto nbr: l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout<<endl;
    }

    void shortestpathBfs(T src){
        map<T, int> dist;
        queue<T> q;

        //mark all the other city as infinity distance
        for(auto pair_city : l){
            dist[pair_city.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;  //starting src with 0 level.

        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        //Printing all distance from src
        for(auto node_pair: l){
            cout<<"Distance to "<<node_pair.first<<" :"<<dist[node_pair.first]<<endl;
        }

    }
};


int main() {
    Graph<int> g;
	g.addEdges(1, 0);
	g.addEdges(0, 2);
	g.addEdges(2, 3);
	g.addEdges(2, 1);

	g.bfs(0);
    g.shortestpathBfs(0);
    // cout<<<<endl;
}
