#include<iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(string a, string b){
	if(a.length() == b.length())
		return a<b;
	else
		return a.length() > b.length();
}

int main(){


	//String init
	string s0;
	string s1("Hello");
	string s2 = "Hello World";
	string s3(s2); //using copy constructor
	string s4 = s3; //assignment also works

	//Check empty
	cout<<"String is empty "<<s1.empty()<<endl; //returns bool or (1,0)

	//Append to add string
	s0.append("Why");
	s0 += " are";
	cout<<s0<<endl;

	//Compare
	cout<<s1.compare(s0)<<endl; //returns ==0for equal, <0 for less, >0 for greater than s0.
	//or we could have also used <,>,== as comparison

	//finding and removing substrings
	string s= "Hello we dont have apple";
	string word = "dont";
	int ind = s.find(word);
	s.erase(ind, word.length()+1); //+1 to remove extra spaces
	cout<<s;

	for(auto i:s){ //For each loop
		//whatever with i;
	}

	for(auto it=s.begin(); it!=s.end(); ++it){
		//whatever with (*it)
	}

	//Sorting
	int n;
	cin>>n;
	cin.get();  //to remove any buffer(extra enters)
	string a[100]; //array of strings
	for(int i=0; i<n; ++i){
		getline(cin,a[i]);
	}

	sort(a,a+n,compare); //Sorting

	for(int i=0; i<n; ++i){
		cout<<a[i]<<endl;
	}


	//String Tokenizer
	//returns a string in parts of deliminators.
	//For the first time pass the whole of string object, and the next time onwards pass NULL
	//as it moves forward. When the string gets ended, tokenizer has NULL value.
	char p[100] = "Hello how are you rainy day";
	char *ptr = strtok(p, " "); //space is the deliminator , first time pass whole string
	cout<<ptr<<endl;
	while (ptr!= NULL){
		ptr = strtok(NULL, " ");
		cout<<ptr<<endl;
	}

}
