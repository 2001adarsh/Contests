#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int *a[n],i,j,x,y;
    int size[100];
    for(i=0;i<n;i++)
    {
        cin>>size[i];
        a[i]=(int *)calloc(size[i],sizeof(int));
        for(j=0;j<size[i];j++)
            cin>>a[i][j];
    }
    for(i=0;i<q;i++)
    {
        cin>>x>>y;
        cout<<a[x][y];
    }
    return 0;
}
