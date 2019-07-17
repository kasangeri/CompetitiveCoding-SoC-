#include <bits/stdc++.h> 
using namespace std; 
map<int,vector<int> > Tree;
int visited[200000];
int Dist(int A, int B, int n)
{
  queue<int> Q;
  Q.push(A);

  long distance[n+1];
  for(int i=0;i<=n;i++){visited[i]=0; distance[i]=0;}
  distance[A]=0;
  visited[A]=1;
  int x = A;
  while(!Q.empty())
	{
        x = Q.front();
 	Q.pop();
	for(int i=0;i<Tree[x].size();i++)
 		{
                   int y = Tree[x][i];
		   if(visited[y])
			continue;
		       {
			distance[y] = (distance[x] + 1);
			Q.push(y);
			
			visited[y]=1;
			}
		
		}
		//Tree[x].erase(Tree[x].begin(),Tree[x].end());
        }

  //queue<int> Q;
  Q.push(B);
  int visitedB[n+1];
  long distanceB[n+1];
  for(int i=0;i<=n;i++){visitedB[i]=0; distanceB[i]=0;}
  distanceB[B]=0;
  visitedB[B]=1;

   while(!Q.empty())
	{
        x = Q.front();
 	Q.pop();
	for(int i=0;i<Tree[x].size();i++)
 		{
                   int y = Tree[x][i];
		if(visitedB[y])
			continue;
		       {
			distanceB[y] = distanceB[x] + 1;
			Q.push(y);
			
			visitedB[y]=1;
			}
		
		}
		//Tree[x].erase(Tree[x].begin(),Tree[x].end());
        }

  long maxx = 0;
  for(int i=1;i<=n;i++)
{
  if(distance[i]>distanceB[i] && distance[i]>maxx) maxx = distance[i];
 }

  return maxx;

}





int main() 
{ 
  int n;
  cin>>n;
  int x;
  cin>>x; 
  int u,v;
  for(int i=1;i<n;i++)
	{
          cin>>u>>v;  
	  Tree[u].push_back(v);
          Tree[v].push_back(u);
        }
  long tox = Dist(1,x,n); 
  //cout<<2*tox;
 cout<<sizeof(int);
} 

