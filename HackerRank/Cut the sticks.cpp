#include<iostream>
using namespace std;
int main()
{
    int small,i,j,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(n>0)
{
    cout<<n<<endl;
    small=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<small)
            small=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==small)
        {
            for(j=i;j<n;j++)
                a[j]=a[j+1];

            n--;
            i--;
        }
    }
    for(i=0;i<n;i++)
     {
       a[i]-=small;
     }
}
    return 0;
}
