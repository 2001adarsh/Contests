#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int n,i,j,r,c,flag=0;
    cin>>n;
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
           scanf("%1d",&a[i][j]);
    }
    i=0;
    for(j=0;j<n;j++)
        cout<<a[i][j];
        cout<<endl;


    int first=0, last=n-1;
    for(i=1; i<n-1; i++)
    {   int large= -37000;
            flag=0;
        for(j=1; j<n-1; j++)
        {
            if(a[i][j]> a[i][first] && a[i][j]> a[i][last] )
            {
                if(a[i][j] > large )
                    { large= a[i][j];
                      flag=1;
                      r=i;
                      c=j;
                    }
            }
        }
    for(j=0;j<n;j++)
    {   if( flag==1)
            {
                if (a[i][j] == a[r][c])
                    cout<<"X";
                else cout<<a[i][j];
            }
         else{
            cout<<a[i][j];
         }
     }
      cout<<endl;
    }
     i=n-1;
    for(j=0;j<n;j++)
        cout<<a[i][j];
        cout<<endl;
    return 0;
}
