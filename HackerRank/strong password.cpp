#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    string password;
    cin>>password;

    string special_characters = "!@#$%^&*()-+";
    int spl=special_characters.length();

    int scnt=0, lcnt=0, ucnt=0, ncnt=0;
    int min=0;

        for(i=0; i<n; i++)
        {
            if(password[i] >= 'A' && password[i] <='Z' )
                ucnt++;
            if(password[i] >='a' && password[i] <='z')
                    lcnt++;
            if(password[i] >='0' && password[i] <='9')
                    ncnt++;
            for(j=0; j<spl;j++)
            {
                if(password[i] == special_characters[j])
                    scnt++;
            }
        }
        if(ucnt==0)
            min++;
        if(lcnt==0)
            min++;
        if(ncnt==0)
            min++;
        if(scnt==0)
            min++;
     if(6-n > min)
     {
         min=6-n;
         cout<<min;
     }
     else cout<<min;
     return 0;
}
