#include<bits/stdc++.h>
using namespace std;

#define sign(a) ( ( (a) < 0 )  ?  -1   : ( (a) > 0 ) )
vector<int> seq;
int main()
{
  int n; 
  cin>>n;
  long a[n];
  cin>>a[0];
  long b[n-1];  
  //intount = 0;
  for(int i =1;i<n;i++)
   {
     cin>>a[i];
     b[i-1] = sign(a[i] - a[i-1]);
   }
  //long d = b[0];
  int I1,I2;
  I1 = -1;
  I2 = -1;
  for(int i = 0; i< n-1 ;i++)
    {  
       if(b[i] == 1) I1 = i;
       else if(b[i] == -1) I2=i;
    } 
 //cout<<I1<< " "<<I2<<endl;
if(I1 == -1 || I2 == -1)
  { cout<<"0\n"; exit(0);}
  if(I1<I2) { cout<<"3\n"<<I1+1<<" "<<(I1+2)<<" "<<I2+2; exit(0);}
  else { cout<<"3\n"<<I2+1<<" "<<I2+2<<" "<<(I1+2); exit(0);}
 
 // cout<<(count+2)<<endl;
  

}
