#include<iostream>
using namespace std;
int fab(int n);
int main(void)
{
   int n, c=0;
   cout<<"Enter the size: ";
   cin>>n;
   for(int i=1; i<=n; i++)
   {
     cout<<fab(c)<<" ";
     c++;
   }
     return 0;
}
int fab(int n)
{
    if(n==0 || n==1)
      return n;
    else
      return (fab(n-1) + fab(n-2));
}


hgfhgfhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhc