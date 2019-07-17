#include<bits/stdc++.h>
using namespace std;

vector< pair <int,int> >  E;

bool compare(const pair<int,int> &a, 
              const pair<int,int> &b)
{
 if (a.first < b.first) return true;
 else if(a.first == b.first && a.second > b.second) return true;
 else return false;
 
 //return false;
}

int main()
{

  int n;
  cin>>n;
  int a,b;
  for(int i = 0;i < n;i++)
   {
      cin>>a>>b;
      E.push_back(make_pair(a,b));
   }
 
 sort(E.begin(),E.end(),compare); 

int count = 0;
int max = 0;
for(int i=0;i<n;i++)
{
  if(E[i].second<max) count++;
  else max = E[i].second;
  
}
cout<<count<<endl;
  
}
 
 
      
