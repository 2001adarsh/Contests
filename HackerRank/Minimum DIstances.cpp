#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, i,j,small;
    cin>>n;
    int a[n],temp[n];
    for(i=0;i<n ; i++)
    {
        cin>>a[i];
    }
    int flag=0;
    int z=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
              {
                temp[z]=abs(i-j);
                flag=1;
                //cout<<abs(i-j);
                z++; }
        }
    }
    //for(i=0;i<z;i++)
   //     cout<<temp[i]<<" ";
    small=temp[0];
    for(i=1;i<z;i++)
    {
        if(temp[i]<small)
            small=temp[i];
    }
    if(flag==1)
    cout<<small;
    else cout<<"-1";
}
