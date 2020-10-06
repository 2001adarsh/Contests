#include<iostream>
using namespace std;
int main()
{
    int i,n,j,count=0,fcount=0,max=0,imax=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==a[i])
                count++;
        }
        if(max<count)
        {
            max=count;
            imax=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==a[imax])
            fcount++;
    }
    cout<<n-fcount;
    return 0;
}
