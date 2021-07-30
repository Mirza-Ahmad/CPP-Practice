#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
int n, len;
char name[60];
cout<<"Enter your name: ";
cin.getline(name, 60);
cout<<"Enter the size of the heart:";
cin>>n;
len=strlen(name);
int i,j;
for(i=n/2; i<=n; i+=2)
{
   for(j=1; j<=n-i; j+=2)
   {
      cout<<" ";
   }
   for(j=1; j<=i; j++)
   {
     cout<<"*";
   }
   for(j=1; j<=n-i; j++)
   {
    cout<<" ";
   }
   for(j=1; j<=i; j++)
   {
       cout<<"*";
   }
   cout<<endl;
}
for(i=n; i>=1; i--)
{
   for(j=i; j<=n; j++)
   {
       cout<<" ";
   }
   if(i==n)
   {
      for(j=1; j<=(n*2-len)/2; j++)
      {
         cout<<"*";
      }
            cout<<name;
         for(j=1; j<=(n*2-len)/2; j++)
         {
         cout<<"*";
         }
   }
   else
   {
     for(j=1; j<=2*i-1; j++)
     {
       cout<<"*";
     }
   }
   cout<<endl;
}
return 0;
}
