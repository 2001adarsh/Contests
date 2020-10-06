#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
     string str;
    int x,y,len;
    double q;
    cin>>str;
    int i,j;
    len=str.size();
    q=sqrt(len);
    x=floor(q);
    y=ceil(q);
     if((x*y)<len)
    {
        x=y;
    }



        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                if((i+j*y)<len)
                    cout<<str[i+j*y];
            }
           cout<<" ";
        }
      return 0;
}
