#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long c,n,t,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>c>>n;
        long z=0,y=0;
        for(j=1;j<=n;j++)
            {z=1+(j-1)*6;
                y+=z; }
        long x=c*y;
        cout<<x<<endl;
        //long g=pow(10,9);
        //cout<<x%(g+7)<<endl;
    }

    return 0;
}
