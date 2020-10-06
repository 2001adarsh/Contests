#include<iostream>
#include<cmath>
using namespace std;
void ans()
{
    int n;
    cin>>n;
    int i,j,count=2,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1 ,j=2; j<n-1; i++, j++)
    {
        if(a[i]==0 || a[j]==0)
            count++;
        else if(a[i]>a[j] )
        {
            if( a[j]<a[j+1] )
                count++;
        }
        /*if(a[i]>a[j])
        {
            if(a[j]>a[j+1] )
                continue;
        } */
    }
    cout<<count;
}
int main()
{
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ans();
    }
}
