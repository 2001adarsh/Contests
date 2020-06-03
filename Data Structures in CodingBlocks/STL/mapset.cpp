#include <iostream>
#include <bits/stdc++.h>
#include <map>  
using namespace std;

class Student{
    public:
    string firstn,last;
    int rollno;
    
    Student(string firstn, string last, int rollno){
        this->firstn = firstn;
        this->last = last;
        this->rollno = rollno;
    }
    bool operator==(const Student& s1) const{
        return rollno == s1.rollno ?true:false; 
    }
};

class hashFun{
    public:
     size_t operator()(const Student& s) const{
        return s.firstn.length() + s.last.length();
    }
};


int main() {

//Maps use "Self balancing BST". which makes all keys in sorted order
map<string, int> m;

    //1. insert
    m.insert(make_pair("Hello", 6));
    
    pair<string ,int> p;
    p.first = "Why";
    p.second = 130;
    m.insert(p);

    m["banana"]= 20;

    //2. Search 
    auto it = m.find("banana");
    if(it!=m.end()){
        cout<<"Banana is present at "<<m["banana"]<<endl;
    }else {
        cout<<"Item not present";
    }

    m.erase("banana");

//Count either returns 1 or 0, as map contains unique elements.
    if(m.count("banana")){
        cout<<"Banana is present at"<<m["banana"]<<endl;
    } else {
        cout<<"Item not present"<<endl;
    }

    for(auto it: m){
        cout<<it.first<<" "<<it.second<<endl;
    }



//Multimap -> stores multiple keys.
    multimap<string, int> mp;

//Unordered_map -> stores keys in random order. But is faster than 
// regular map, as it takes O(1) in average case for all operation,
//here we are building a custom Unordered_map .

    unordered_map<Student, int, hashFun> um;
    Student s1("Adarsh", "Singh", 19);
    Student s2("Bola", "Cola", 20);
    Student s3("Hello","Bella", 31);
    

    //For unordered map, it is neccessary to define operator overloading
    //(==) as it will be the base between comparing two objects;1

    //adding marks to student
    um[s1] = 100;
    um[s2] = 96;
    um[s3] = 99;

    for(auto s: um){
        cout<<s.first.firstn<<" "<<s.first.last<<endl;
    } 

    //set -> contains unique elements uses Tree like data structure
    //It can be a BST, Red-Black Tree or any other.
    set<int> st;
    //takes logN time
    return 0;
}
