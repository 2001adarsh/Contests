#include<iostream>
#include<math.h>
using namespace std;
void sqr(int a, int b)
{
  int i;
  float x;
  int count=0;
  for(i=a;i<=b;i++)
  {
    x=sqrt(i);
   int j=x;
    if(j==x)
      count++;
  }
 cout<<count<<endl;
}

int main()
{
 int q,a,b;
 cin>>q;
 for(int i=0;i<q;i++)
 {
   cin>>a>>b;
   sqr(a,b);
 }
return 0;
}
