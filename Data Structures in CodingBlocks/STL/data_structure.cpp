#include <bits/stdc++.h>
using namespace std;

int main(){

    /*List --> Doubly linked list
    useful when insertion and deletion of data from middle
     methods	->
     push_back(), push_front(), pop_back(), pop_front(),
     insert(), erase(ind), remove(val)-> removes all occ of 2
     */
    list<string> l({"apple", "banana", "guava", "mango" });
    l.push_back("water");
    l.push_back("water");
    l.push_back("water");
    l.sort();
    l.reverse();
    l.pop_front();

    for(string s: l){
    	cout<<s<<"-->";
    }
    cout<<endl;
    l.remove("water"); // removes all occurence of "water"
    for(string s: l){
    	cout<<s<<"-->";
    }
    cout<<endl;

    //erasing elements
    list::iterator it= l.begin();
    it++;
    it++;
    l.erase(it);
 	l.insert(it,"FruitJuce");
	for(string s: l){
    	cout<<s<<"-->";
    }
    cout<<endl;

    /* Stack
    	methods -> push(data), pop(), empty(), top(); */
    /* Queue
    	methoda -> push(data), front(), pop(), empty() */

    /* Priority Queue -> actually implemented as a heap (higher priority comes first)
    	push and pop -> log(N) top -> o(1)

        for MIN heap representation -> priority_queue<int, vector<int>, greater<int> > pq;
    	*/
    priority_queue<int> pq;
    for (int i=0; i<5; i++){
    	pq.push(i*5);
    }
    while(!(pq.empty())){
    	cout<<pq.top()<<" ->";
    	pq.pop();
    }

    return 0;
}
