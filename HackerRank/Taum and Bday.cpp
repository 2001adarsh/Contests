#include<iostream>
using namespace std;
int main()
{
    long b,w,bc,wc,z;
    long i,t;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>b>>w;
        cin>>bc>>wc>>z;
        if(bc > wc)
        {
            if(bc > wc +z)
               { bc=z+wc; }
        }
        else if( bc < wc)
        {
            if( wc > bc+z)
                { wc=z+bc; }
        }

    cout<<((b*bc)+(w*wc))<<endl;
    }
    return 0;
}
