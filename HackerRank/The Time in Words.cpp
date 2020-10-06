#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,h,m;
    cin>>h>>m;
    string number[100] = { "zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three","twenty four",
        "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine" , "thirty" };

    if(m==0)
        cout<<number[h]<<" o' clock";
    else if(m==15)
        cout<<"quarter past "<<number[h];
    else if( m==30 )
        cout<<"half past "<<number[h];
    else if( m==45 )
        cout<<"quarter to "<<number[h+1];
        else if( m==1)
            cout<<number[m]<<" minute past "<<number[h];
    else if( m<30)
        cout<<number[m]<<" minutes past "<<number[h];
    else if( m>30 )
        cout<<number[60-m]<<" minutes to "<<number[h+1];
    else if(m==59)
        cout<<number[60-m]<<" minute to "<<number[h+1];

     return 0;
}
