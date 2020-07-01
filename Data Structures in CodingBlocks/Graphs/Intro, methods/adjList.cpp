#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l; //declaring a pointer since V is not initialised yet

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; //initialising the size of list.
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<"Vertex "<<i<<" -> ";
            for(int ngb : l[i]){
                cout<<ngb<<", ";
            }
            cout<<endl;
        }
    }

};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printAdjList();
}
