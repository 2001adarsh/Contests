#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person{
public:
    string name;
    int age;
    Person() {
    }

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

};

class PersonCompare{
    public:
    bool operator()(Person A, Person B){
        return A.age < B.age;
    }
};

int main() {
    int n;
    cin>>n;
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    
    for(int i=0; i<n; ++i){
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p);
    }

   while(!pq.empty()){
       Person p = pq.top();
       cout<<p.name<<" "<<p.age<<endl;
       pq.pop();
   }

    return 0;
}

