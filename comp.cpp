#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
 if(a.first == b.first) return a.second>b.second;
 else return a.first<b.first;
}

int main()
{
 int n;
 cin>>n;
 int a,b;
 cin>>a>>b;
 vector<pair<int,int> > A;
 int v;
 for(int i = 0;i<n;i++) 
    {
     cin>>v;
        
     A.push_back(make_pair(v,i));
      //A[i][1] = i;
     }

if(a==b) {
          for(int i = 0;i<a;i++){cout<<"1 ";}
          while(b>0) {cout<<"2 "; b=b-1;}
         }
else if(a<b)
 {
   sort(A.begin(),A.end(),comp);
  
  int S[n];
  for(int i = 0;i<n;i++){ if(i<a) {S[A[n-1-i].second] = 1;}
                          else S[A[n-i-1].second] = 2;}
 
  for(int i = 0;i<n;i++) cout<<S[i]<<" ";

 } 
else
 {
   sort(A.begin(),A.end());
  
  int S[n];
  for(int i = 0;i<n;i++){ if(i<a) {S[A[i].second] = 1;}
                          else S[A[i].second] = 2;}
 
  for(int i = 0;i<n;i++) cout<<S[i]<<" ";

 } 
 


}
