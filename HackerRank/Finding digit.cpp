#include<iostream>
using namespace std;
int funct(int n)
{
    int i,j,k,count=0;
    j=n;
    while(j>0)
    {
        k=j%10;
        if(n%k==0)
            count++;
        j=j/10;
    }
    return count;
}
int main()
{
    int i,t,n,count;
    cin>>t;
    for(i=0;i<t;i++)
    {   cin>>n;
        count=funct(n);
        cout<<count<<endl;
    }
    return 0;
}
