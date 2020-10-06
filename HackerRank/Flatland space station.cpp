#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i, j, n, m;
    cin>>n>>m;
    int a[m];
    for(j=0;j<m;j++)
        cin>>a[j];
    if(m==n)
    {
        cout<<"0";
    }
    else
    {
      int distance=0;
      int temp;
            for(i=0;i<n;i++)
            {
               temp=abs( i - a[0]);
              for(j=0; j<m; j++)
             {
                temp=min( temp, abs(a[j]-i) );
            }
                distance= max(distance, temp);
            }
        cout<<distance;
    }
    return 0;
}
