#include<bits/stdc++.h>
using namespace std;

set<int>sizes;
set<int> iterator itr;
vector<int,int> balls;
vector<int,int>::iterator it;

int main()
{
 int n;
 cin>>n;
 int e;
 for(int i=0;i<n;i++)
  {
    cin>>e;
    sizes.insert(e);
    it = balls.find(e);
    if(it == balls.end()) balls.insert(pair<int,int>(e,1));
    else balls[e]++; 

  }
 itr = sizes.begin();
 int j = 0;
 for(!size.empty())
   {
     e = *itr;
     if(balls[e] == 1) { size.erase(e); cout<<e<<" "; 
     

  }

}
