#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int p,d,s,m,sum,i,count=0;
    cin>>p>>d>>m>>s;
    sum=p;
    for(i=1; ;i++)
    {
        if(sum<=s)
        {
            count++;
            if((p-i*d) > m)
            {
                sum+=(p-i*d);
            }
            else sum+=m;
        }
        else
            break;
    }
   cout<<count;
   return 0;
}
