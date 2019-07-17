        #include<bits/stdc++.h>
         
        using namespace std;
        const int N = 3020;
     
        queue<pair<int,int> > q;
        int main()
        {
            int n,m,k;
            cin >> n >> m >> k;

        vector<int> V[n];
        int dist[n][n],previous[n][n];
    	set<tuple<int,int,int> > C;
            for (int i = 1; i<=n; i++)
                for (int j = 1; j<=n; j++)
		   {	
                    //for(int k=1;k<=n;k++) C.insert(make_tuple(i-1,j-1,k-1));
                    dist[i-1][j-1] = INT_MAX;
                   }
            for (int i = 1; i<=m; i++)
            {
                int x,y;
                cin >> x >> y;
                V[x-1].push_back(y-1);
                V[y-1].push_back(x-1);
            }
         int u,v,w;
         for(int i=0;i<k;i++) { cin>>u>>v>>w; C.insert(make_tuple(u-1,v-1,w-1));}
            dist[0][0] = 1;
            q.push(make_pair(0,0));
            while (!q.empty())
            {
                int v = q.front().first, u = q.front().second;
                q.pop();
                for (int i=0;i<V[v].size();i++)
                {
                    w = V[v][i];
                    if (dist[v][w]>1+dist[u][v] && !C.count(make_tuple(u,v,w)))
                    {
                        dist[v][w] = 1+dist[u][v];
                        previous[v][w] = u;
                        q.push(make_pair(w,v));
                    }
                }
            }
     
     
            int Min = INT_MAX, poz;
            for (int i = 0; i<n; i++)
             {   if (dist[i][n-1]<Min)
                {
                    Min = dist[i][n-1];
                    poz = i;
                }
             }
            if (Min == INT_MAX)
                cout << -1;
            else
            {
                cout << Min-1<<"\n";
                int v = n-1, u = poz;
                stack<int> ans;
                ans.push(v);
                while (v)
                {   
                    //if(v==0) break;
                    ans.push(u);
                    int z = u;
                    u = previous[u][v];
                    v = z;
                }
               while(!ans.empty()) {cout<<ans.top()+1<<" "; ans.pop();}
            }
        }
