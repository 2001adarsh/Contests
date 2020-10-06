#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-2 ,j=n-1; i>=0 && j>=0; i++ ,j++)
    {
            if(a[i] > a[j])
            {
               int temp=a[j];
                a[j]=a[i];
                for(int ai=0;ai<n;ai++)
                    cout<<a[ai]<<" ";
                cout<<endl;
                a[i]=temp;
            }
        }

    return 0;
}
