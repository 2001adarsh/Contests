#include<iostream>
#include<cmath>
using namespace std;
void ans()
{   int n,c,m,i,total,rem,count=0;
    cin>>n>>c>>m;
    int k=n/c;
    count+=k;
    if(k/m>=1)
    {   rem= k%m ;
            rem+=k;
            while(rem){
                int j;
                j=rem/m;
                count+=j;
                rem=rem%m;
            }
        cout<<count;
    }
    else cout<<count;
    return ;

}

int main()
{
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ans();
    }
    return 0;
}
