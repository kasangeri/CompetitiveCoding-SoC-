#include<bits/stdc++.h>
using namespace std;

struct entry
{
 int s;
 int e;
 int index;
 entry(int s, int e, int index): s(s), e(e),index(index){}
};
struct Compare{
  bool operator()(entry const& e1,entry const& e2)
   {
    return((e1.s > e2.s)|| (e1.s==e2.s && e1.index > e2.index));
   }
};

priority_queue<entry, vector<entry>, Compare> Q;
queue<int> result;
  
void gets_when(priority_queue<entry, vector<entry>, Compare> Q, int size)
{
 int time = 0;
 while(!Q.empty())
 {
  entry top = Q.top(); 
  //cout<<top.s<<" "<<top.e<<endl;
  if(top.s > time) {time = top.s; result.push(time);}
  else if( (top.s <= time) && (top.e > time))
   {time=time+1; result.push(time);}
  else {result.push(0);}  
  Q.pop();
 }
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
 {
  int n;
  cin>>n;
  int l, r;
  for(int j = 0; j <n; j++)
   {
    cin>>l>>r;
    Q.push(entry(l,r,j)); 
   }
 
 gets_when(Q,n);
 while(!Q.empty())
  { Q.pop();}
 while(n>0)
 { n--;
  cout<<result.front()<<" ";
  result.pop();
 }
 cout<<endl;
 } 
  
}


