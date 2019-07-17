// Program to find Dijkstra's shortest path using STL set 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
#define ll long long
vector<int> train;
vector<int> road;
int n;
vector<int> dist; 
map<int, vector<pair<int, int> > > adj; 
void addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

void shortestPath(int src) 
{ 
	set< pair<int, int> > setds; 
	setds.insert(make_pair(0, src)); 
	dist[src] = 0; 

	while (!setds.empty()) 
	{ 
		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 

		int u = tmp.second; 

		vector< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			int v = (*i).first; 
			int weight = (*i).second; 

			if (dist[v] > dist[u] + weight) 
			{ 
				if (setds.find(make_pair(dist[v], v)) != setds.end()) 
					setds.erase(setds.find(make_pair(dist[v], v))); 
				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 
} 

// Driver program to test methods of graph class 
int main() 
{ 
int m,k;
cin>>n>>m>>k;
int u,v,w;
int A[m][3];
for(int i=0;i<n;i++) 
{ train.push_back(INF); road.push_back(INF); dist.push_back(INF);}

for(int i=0;i<m;i++) 
   { 
	cin>>u>>v>>w;
	A[i][0]=u-1;A[i][1]=v-1;A[i][2]=w;
   }

for(int i=0;i<k;i++) 
{
	cin>>u>>w;
        addEdge(0,u-1,w);
	train[u-1] = w;
}

shortestPath(0);
vector<int> distTrain;
for(int i=0;i<n;i++) { distTrain.push_back(dist[i]);}

for(int i=0;i<m;i++)
{
addEdge(A[i][0],A[i][1],A[i][2]);  
}
shortestPath(0);
for(int i=0;i<n;i++) { cout<<dist[i];}

return 0; 
} 

