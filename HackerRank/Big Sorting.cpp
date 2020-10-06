#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    string num[n];
    for(i=0;i<n;i++)
        cin>>num[i];
    for(i=0;i<n; i++)
    {
        for(j=i+1;j<n;j++)
        {
            string temp;
            if(num[i].length() > num[j].length())
            {
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
            else if(num[i].length()==num[j].length() )
            {
              if( (num[i].compare(num[j])) > 0 )
              {
                  temp=num[i];
                  num[i]=num[j];
                  num[j]=temp;
              }
            }
        }
    }
    for(i=0; i<n; i++)
        cout<<num[i]<<endl;
    return 0;
}
