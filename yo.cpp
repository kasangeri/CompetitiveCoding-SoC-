#include<bits/stdc++.h>
using namespace std;

set < pair<int,int> > entries;

int main()
{
 int t;
 cin>>t;
 int n,r;
 for(int k=0;k<t;k++)
  {
    cin>>n>>r;
    int i,c;
    for(int j = 0;j <r; j++)
      { 
        cin>>i>>c;
        entries.insert(make_pair(i,c));
      }
    //cout<<entries.size();
   if(entries.size() == r) cout<<"Scenario #"<<(k+1)<<": possible\n";
   else cout<<"Scenario #"<<(k+1)<<": impossible\n";
   entries.erase(entries.begin(),entries.end());
 }

}
