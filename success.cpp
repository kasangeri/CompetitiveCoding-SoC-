#include<bits/stdc++.h>
using namespace std;

int maxi(int a,int b,int c)
{
 if(a>b)
   { 
         if(a>c) return a;
           else return c;}
 else
   {
      if(b>c) return b;
      else return c;
   }
}

int main()
{
 int n;
 cin>>n;
 long long x,y,p,q;
 for(int i = 0;i<n;i++) 
  {
     cin>>x>>y>>p>>q;
     long long m,k;
     if((p == q && x!=y)||(x!=0 && p==0) || q==0) {cout<<"-1\n";}
     else if(p==q && x==y) cout<<"0\n";
     else
      {
       if(x==0&& p==0) m = 0;
       else if(x%p!=0) m = x/p + 1;
       //else 
       else m = x/p;

       if(y%q!=0)  k = y/q + 1;
       else  k = y/q;       
       
       long long r = (y-x)%(q-p);
       //cout<<m<<n<<r<<endl;
       long long o = ((y-x)/(q-p));
       //cout<<o<<endl;
       if(r != 0) o = o+1;
          
       o =  maxi(m,k,o);
       //cout<<o<<endl;
       cout<<(q*o - y)<<"\n";
      }   
  }

 }
