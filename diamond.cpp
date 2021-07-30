#include<iostream>
using namespace std;
int main(void)
{
int n;
cout<<"Enter the size of the diamond:";
cin>>n;
int i,j;
for(i=1; i<=n; i++)
{
    for(j=1; j<=n-i; j++)
    {
        cout<<" ";
    }
    int k;
    for(k=1; k<=2*i-1; k++)
    {
        cout<<"*";
    }
    cout<<endl;
}
i--;
int y, p, l;
for(y=i; y>=1; y--)
{
    for(l=j; l<=n-y; l++)
    {
        cout<<" ";
    }
    for(p=j; p<=2*y-1; p++)
    {
        cout<<"*";
    }
    cout<<endl;
}
return 0;
}
