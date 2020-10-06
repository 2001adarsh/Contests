#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i,j,k;
    string s;
    cin>>s;
    int len=s.length();

    for(i=0; i<len; i++)
    {
        if(s[i]==s[i+1])
        {
            for(k=i, j=i+2; j<len; k++, j++)
            {
                s[k]=s[j];

            }
            i= -1;
            len-=2;
        }
    }
    if(len==0)
        cout<<"Empty String";
    else
        for(i=0;i<len;i++)
        cout<<s[i];
    return 0;
}
