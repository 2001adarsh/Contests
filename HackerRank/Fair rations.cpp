#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int count=0,n,i,j,sum=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if((sum%2) != 0)
        cout<<"NO";
    else{
        for(i=0;i<n;i++)
        {
            if((a[i]%2)==1 && a[i+1]%2==0 && a[i+2]%2==1)
            {
                a[i]+=1;
                a[i+1]+=2;
                a[i+2]+=1;
                count+=4;
            }
        }
        cout<<count;
    }
    return 0;
}
