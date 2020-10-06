#include<iostream>
#include<cmath>
using namespace std;
void ans()
{
    double x,y,a,b;
    double z;
    cin>>a>>b;
    x= pow(a,2)+pow(b,2);
    //cout<<x<<endl;
    double q = pow(a,2)- pow(b,2);
    if(q<0)
        q= abs(q);
    //cout<<q<<endl;
    z=sqrt( x);
    y=sqrt(q);
    //cout<<z<<endl<<y<<endl;
    if(z-(int)z==0 || y-(int)y ==0)
        cout<<"YES";
    else cout<<"NO";

}

int main()
{
    int i,t;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ans();
        cout<<endl;
    }
}
