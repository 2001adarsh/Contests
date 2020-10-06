#include<iostream>
#include<cmath>
using namespace std;
#define MAX
int main()
{
    int i,n,t,j;
    cin>>n>>t;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int c,d;
    for(i=0;i<t;i++)
    { int small= 30000;
        cin>>c>>d;
        for(i=c; i<=d; i++)
        {
            if(a[i]<small)
                small=a[i];
        }
        cout<<small;
    }
    return 0;
}
