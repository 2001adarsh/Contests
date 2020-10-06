#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    int n,i;
    string earth;
    cin>>earth;
    n=earth.length();
    string org="SOS";
    int k=n/3;
    stringstream s;
    for(i=0; i<k; i++)
    {
        s << org;
    }
    string ss;
    s>>ss;
    int count=0;
   // cout<<endl<<ss;
    for(i=0; i<n; i++)
    {
        if(earth[i] != ss[i])
            count++;
    }
    cout<<count;
    return 0;
}
