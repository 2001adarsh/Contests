#include<iostream>
#include<cmath>
#include<cstring>
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

    cout<<len<<" "<<q<<" "<<x<<" "<<y;
int z=0;
    if((x*y)<len)
    {
        x=y;
    }

    char str1[x][y];
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            str1[i][j]=str[z];
            z++;
        }
    }

    for(j=0;j<y;j++)
    {
        for(i=0;i<x;i++)
        {
            cout<<str1[i][j];

        }
        if(j==(y-1))
            break;
        cout<<" ";
    }
    return 0;
}
