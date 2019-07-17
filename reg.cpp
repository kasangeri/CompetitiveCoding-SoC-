#include<bits/stdc++.h>
using namespace std;

map<string,int> names;
map<string, int>::iterator itr; 
//map<string,int> iterator it;
int main()
{
  //names.insert(pair<string,int>("Blehhh",5)) ;
  //cout<<names["Blehhh"];
  int n;
  cin>>n; 
  string str;
  for(int i=0;i<n;i++)
    {
      cin>>str;
      itr = names.find(str);
      if(itr == names.end()) {names.insert(pair<string,int>(str,1)); cout<<"OK\n";}
      else { cout<<str<<names[str]<<"\n"; names[str]++; }
    }

}
