#include<bits/stdc++.h>
 
using namespace std;


int main()
{
 int n,m;
 cin>>n>>m;
 set<int> Alive;
 set<int>::iterator it;
 int killedby[n+1];
 for(int i=1;i<=n;i++) Alive.insert(i);
 int l,r,x;
 for(int i=0;i<m;i++)
 {
  cin>>l>>r>>x;
  it = Alive.lower_bound(l);
  queue<int> Q;
  while(it!=Alive.end())
   { if(*it>r) break; 
    int willdie = *it;
    it++;
    if(willdie != x) { killedby[willdie] = x; Q.push(willdie);}
  }
   while(!Q.empty()) 
   {
     Alive.erase(Q.front());
     Q.pop();

   }
 }

 for(int i=1;i<=n;i++) { if(i==x) cout<<0<<" "; else cout<<killedby[i]<<" ";}

}
