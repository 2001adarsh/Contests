#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    string s;
    char c;
    cin>>s;
    int k;
    cin>>k;

    for(i=0;i<n;i++)
    {
        if(isalpha(s[i]))
        {
            c = isupper(s[i])?'A' : 'a';
            s[i]= c+ (s[i]- c +k)%26;
        }
    }
    cout<<s;
    return 0;
}
