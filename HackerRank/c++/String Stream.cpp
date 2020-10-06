#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string a,b,c;
    stringstream ss(str);
    //ss << str; //sending the values of str in stream
    int word; //To store individual words of a string
    char ch;
    while(ss >> word >> ch)
    {
        cout<<word<<endl;
    }
    ss>>word;
    cout<<word;
    return 0;
}
