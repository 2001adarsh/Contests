#include<iostream>
using namespace std;
void ans()
{
    int i,j,n;
    cin>>n;
    char a[n];
    int count[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int ucount=0;
    for(i=0;i<n;i++)
    {   count[i]=0;
        if(a[i]=='_')
            ucount++;
        else
        {
            for(j=0;j<n;j++)
            {
                if(a[i]==a[j])
                    { count[i]++;
                    }
            }
        }
    }
    int flag;
    if(ucount==0)
        {  flag=0;
            if(n==1)
                cout<<"NO"<<endl;

            for(i=1;i<n;i++)
                if(a[i-1]!=a[i] && a[i]!=a[i+1])
                    { cout<<"NO"<<endl;
                       flag=1;
                        break; }
           if(flag==0 && n!=1)
              cout<<"YES"<<endl;
        }
    else
    {   flag=0;
        for(i=0;i<n;i++)
            { if(count[i]==1)
                { cout<<"NO"<<endl;
                    flag=1;
                    break;}
            }
    if(flag==0)
                cout<<"YES"<<endl;
    }


}
int main()
{   int i,t;
    cin>>t;
    for(i=0;i<t;i++)
        ans();

    return 0;
}
