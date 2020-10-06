#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int count=1;

    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] < 97)
            count++;
    }
        cout<<count;
        return 0;
}
