#include<iostream>
#include<cmath>
#include<sstream>
#include<cstring>
using namespace std;

void multiply(int num1, int num2)
{
    stringstream ss;
    ss<<num1;
    string str1;
    ss >> str1;
    stringstream sd;
    sd << num2;
    string str2;
    sd >> str2;

    int len1=str1.size();
    int len2=str2.size();
    int i,j, count=0,ans[len1+len2];
    int x=0;
    int y=0;
    for(i=len1-1;i>=0;i++)
    {
        int carry=0;
        int len1 = str1[i] - '0';
        y=0;
        for(j=len2-1; j>=0;j++)
        {
            len2=str2[j]-'0';
            int sum= len1*len2+ ans[x+y]+carry;
            carry=sum/10;
            y++;
        }
        if(carry>0)
            count++;
        x++;
    }

    cout<<count;
    return ;
}


int main()
{
    int i,num1,num2,t;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>num1>>num2;
        multiply(num1,num2);
    }
    return 0;
}
