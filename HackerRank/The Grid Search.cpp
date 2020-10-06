#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
void ans()
{
     int i,j,R,C,r,c;
    cin>>R>>C;
    int A[R][C];
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            scanf("%1d",&A[i][j]);
    cin>>r>>c;
    int B[r][c];
    for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%1d",&B[i][j]);

    int g=B[0][0],x,y,flag=0;
    for(i=0;i<R-r;i++)
        {for(j=0;j<C-c;j++)
    {
        if(A[i][j]==g)
        {
            int u=0,v=0;
                x=i;
                y=j;
            for( ;x < i+r ;x++ )
            {
                for( ;y< j+c;y++)
                {
                    if(A[x][y]==B[u][v])
                        flag=1;
                    else
                    {
                        flag=0;
                        break;
                    }
                    v++;
                }
                u++;
            }
            if(flag==0)
                continue;
            else
                break;
        }

    }
        }
    if(flag==1)
            cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
     return ;
}


int main()
{ int i,t;
    cin>>t;
    for(i=0;i<t;i++)
        ans();
    return 0;
}
