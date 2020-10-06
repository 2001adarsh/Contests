#include<iostream>
using namespace std;
int main()
{
    int i,j,n,k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l,t=2*n;
    int z, temp[t];
    for(i=0;i<n;i++)
    { l=0;
        for(j=i+1;j<n;j++)
        {
            z=a[i]+a[j];
            if(z%k==0)
            {
              temp[l]=i;
              temp[l+1]=j;
              l+=2;
            }
        }
    }
    for(i=0;i<l;i++)
        cout<<temp[i];
}
