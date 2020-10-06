#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,i,j,r,count=0;
    cin>>n>>r;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(abs(a[i]-a[j])==r)
            {
               cout<<a[i]<<" "<<a[j]<<endl;
                count++;
            }
        }
    }
    cout<<count;
    return 0;

}
