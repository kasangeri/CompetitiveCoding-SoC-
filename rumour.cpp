#include<bits/stdc++.h>
using namespace std;

map<int,vector<int> > Tree;


void getgraph()
{
 int n,e;
 cin>>n>>e;
 int u,v;
  for(int i=0;i<e;i++)
	{
          cin>>u>>v;  
          //if(u>v)
	  Tree[u].push_back(v);
          //else
          Tree[v].push_back(u);
        }
 
}



int main()
{
 //getgraph();
 long long n,e;
 cin>>n>>e;
 long long A[n+1];
 A[0] = -1;
 for(int i=0;i<n;i++) cin>>A[i+1];
 int u,v;
 for(int i=0;i<e;i++)
	{
          cin>>u>>v;  
          //if(u>v)
	  Tree[u].push_back(v);
          //else
          Tree[v].push_back(u);
        } 
 
 set<int> V;
 set<int>::iterator it;
 set<long long>::iterator itn;
 long long count = 0;
 for(int j=1;j<=n;j++){ V.insert(j);}
 //if(V.find(4)==V.end()) cout<<"Hii";
 //V.clear();
 
 queue<int> Q;
 set<long long> N;
 while(!V.empty())
 {

   it = V.begin();
   int ver = *it;
   Q.push(ver);
   N.insert(A[ver]);
   V.erase(it);
   while(!Q.empty())
   { 
     ver = Q.front();
      Q.pop();
     for(int k=0;k<Tree[ver].size();k++)
       {
        
          int x = Tree[ver][k];
          //cout<<"Searching"<<x<<"\n";
          if(V.find(x) == V.end())
           {
             continue;
           }
          else {
             Q.push(x);
             N.insert(A[x]);
	     V.erase(V.find(x));
            }
          // Q.erase(Q.begin(),Q.end());
        }
 }

   itn = N.begin();
   count = count + (*itn);
   N.clear();

 }
 
 cout<<count;
}
