#include <bits/stdc++.h>
using namespace std;

class Graph{
    //HashMap to store values other than int nodes
    unordered_map<string, list<pair<string, int> > > l;

public:
    void addEdge(string x, string y, bool bidrec, int wt){
        l[x].push_back(make_pair(y, wt));
        if(bidrec)
            l[y].push_back(make_pair(x, wt));
    }

    void printAdjList(){
        
        for(auto i: l){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j.first<<", ";
            }
            cout<<endl;
        }
    }

};

int main() {
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("B", "D", true, 30);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 20);

    g.printAdjList();
}
