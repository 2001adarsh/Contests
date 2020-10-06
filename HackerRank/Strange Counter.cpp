#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long n,i,j,k=3,t=1;
    cin>>n;

    while(t<n)
    {
        j=0;
        j=t+k;
        if(j>n)
            break;
        else
        {
            t=j;
            k=2*k;
        }
    }
    if(t==n)
        cout<<k;
    else{
        for(i=t; i<n;i++)
        {
            k--;
        }
        cout<<k;
    }
    return 0;

}
