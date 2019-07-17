#include<bits/stdc++.h>
using namespace std;


int main()

{

 int n;
 cin>>n;
 int a[n];
 int diff;
 string b;
 for(int i=0;i<n;i++) 
  {cin>>a[i];
  }
 int highest = 0;
 cin>>b;
 for(int i=0;i<n;i++)
  {
    diff = a[i] - (i+1);
    if(diff>0)
       {
         // std::string s(diff, '1'); // s == "aaaaa"
          //string str = b.substr(i,diff);
         // if(str != s) { cout<<"NO\n"; return 0;}
     if(highest > i)
       { for(int j = highest; j<i+diff;j++) 
          {
           highest = j;
           if(b[j]!='1'){ cout<<"NO\n"; return 0;}
          }
        }
     else  
         { for(int j = i; j<i+diff;j++) 
          {
           highest = j;
           if(b[j]!='1'){ cout<<"NO\n"; return 0;}
          }
        }

   }

 
 //   else if(diff<0)
 //{
   // std::string s(-1*diff,'1');

   // string str = b.substr(i+diff,-1*diff);
   // if(str != s) {cout<<"NO\n"; return 0;}
     // for(int j = i+diff;j<i;j++) 
       // { 
         //if(b[j]!='1') {cout<<"NO\n"; return 0;}
          //}  
  //}
 
 }
cout<<"YES\n"; 
}
