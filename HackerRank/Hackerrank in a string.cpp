#include<iostream>
#include<string>
using namespace std;
int main()
{   string h="hackerrank";
    int t,hl=h.length();
    cin>>t;

    for(int i=0;i<t;i++)
    {
    string word;

        int flag=0;
        cin>>word;
        int j=0;
    int len=word.length();
    if(len < hl)
        cout<<"NO";
    else{
        for(int i=0;i<len;i++)
        {
            if(word[i]==h[j])
            {
                j++;
            }
        }
        if(j==hl)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

    return 0;
}
