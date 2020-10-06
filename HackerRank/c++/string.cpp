#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b, c;
    int x,y;
    cin>>a>>b;
    x=a.size();
    y=b.size();
    cout<<x<<" "<<y<<endl;
    char o,p;
    c=a+b;
    cout<<c<<endl;
    o=a[0];
    p=b[0];
    a[0]=p;
    b[0]=o;
    cout<<a<<" "<<b;
    return 0;
}
