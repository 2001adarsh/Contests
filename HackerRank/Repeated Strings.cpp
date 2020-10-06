#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
    int i,times,count=0;
    long long n;
    char str[100];
    fgets(str,100,stdin);
    int len=strlen(str)-1;
    cin>>n;
    int letter=0;
    for(i=0;i<len;i++)
        if(str[i]=='a')
            letter++;
    int div,half;
    div=n/len;
    half=div*letter;
    int rem;
    rem=n%len;
    for(i=0;i<rem;i++)
    {
        if(str[i]=='a')
            count++;
    }
    int total;
    total=half+count;
    cout<<total;
    return 0;
}
