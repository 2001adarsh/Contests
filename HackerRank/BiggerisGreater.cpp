#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int main()
{
    int len,i,j,flag=0,count=0;
    char temp;
    string s;
    cin>>s;
    len=s.size();
    for(i=len-1;i>=0;i--)
    {
        for(j=len-2; j>i && s[j]<s[i];j--)
        {
            if(s[i]<s[j])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                count++;
                flag=1;
                break;
            }
        }
       if(flag==1)
            break;
    }
    if(count==0)
        cout<<"no answer";
    else cout<<s;
    return 0;
}
