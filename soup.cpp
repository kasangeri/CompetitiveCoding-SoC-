#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n; 
  cin>>n;
  float a[n];
  int V; cin>>V;
  float b[n];
  float min = INT_MAX;
  int index = -1; 
  float total = 0;
  for(int i = 0;i<n;i++) { cin>>a[i]; total = total + a[i];}
  for(int i = 0;i<n;i++) 
  {  
      cin>>b[i]; 
      if(b[i]/a[i] <= min) 
        {min = b[i]/a[i]; index = i;}
  }
  //float x;
  float x = (min);
  float fin = (x) * (total);
  //cout<<fin;
  if(fin <= V) cout<<fin;
  else cout<<V;

  


}
