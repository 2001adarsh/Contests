#include<iostream>
#include <limits.h>
#include <math.h>
using namespace std;
int main()
{
    long i,j,k,n,sum,x,y,flag=0;
    cin>>x>>y;
    for(i=x;i<=y;i++)
    { sum=0;
      long right,left,q,w,digit=0;
        n=pow(i,2);
        j=i;
        while(j>0)
        {
            j/=10;
            digit++;
        }
        int g=pow(10,digit);
        right= n % g;
        left=n / g;
        sum=right+left;
       if(sum==i)
       { cout<<i<<" ";
            flag=1;}
    }
    if(flag==0)
        cout<<"INVALID RANGE";
    return 0;
}
