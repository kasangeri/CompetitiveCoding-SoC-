#include<bits/stdc++.h>
 
using namespace std;
vector<int> open,close,done;
 string s;
void build(int x,int l, int r)
{
  //cout<<x<<endl;
   if(l>0 && r<=s.size())
{
   if(l==r)
   {
     if(s[l-1] == '(') { open[x] = 1; close[x] = 0; done[x] =0;}
     else if(s[l-1] == ')') {close[x] = 1;open[x] = 0; done[x] =0;}
    // cout<<x<<endl;
     return;
   }
 else
  {
   //cout<<"here";
   int m = (l+r)/2;
   build(2*x,l,m);
   build(2*x+1,m+1,r);
   int yo = min(open[2*x],close[2*x+1]);
   open[x] = open[2*x] + open[2*x+1] - yo;
   close[x] = close[2*x] + close[2*x+1] - yo;
   done[x] = done[2*x] + done[2*x+1] + 2*yo;
  }

}
}


tuple<int,int,int> query(int x, int start, int end, int l, int r)
{
  //if(start==end) return make_tuple(done[x],open[x],close[x]);
  if(r<start || end<l) return make_tuple(0,0,0);
  if(l<=start && r>= end) return make_tuple(done[x],open[x],close[x]);
  int mid = (start + end) / 2;
  //if(mid>=r) return query(2*x,start,mid,l,r);
  //if(mid<l) return query(2*x+1,mid+1,end,l,r);
  tuple<int,int,int> p1 = query(2*x, start, mid, l, r);
  tuple<int,int,int> p2 = query(2*x+1, mid+1, end, l, r);
  int yo = min(get<1>(p1),get<2>(p2));
  int d = get<0>(p1) + get<0>(p2) + 2*yo;
  int o = get<1>(p1) + get<1>(p2) - yo;
  int c = get<2>(p1) + get<2>(p2) - yo;
  return make_tuple(d,o,c); 
}

int main()
{

 cin>>s;
 int m;
 cin>>m;
 int n;
 for(n=0;s[n];n++){} 
 for(int i=0;i<=2*n;i++) {open.push_back(0);close.push_back(0);done.push_back(0);}
 build(1,1,n);
 int l,r;
 for(int i=0;i<m;i++)
 {
  cin>>l>>r;
  cout<<get<0>(query(1,1,n,l,r))<<"\n";
 }
 //cout<<open[4]<<open[5]<<open[6]<<open[7]<<"\n";
 //cout<<close[4]<<close[5]<<close[6]<<close[7]<<"\n";
 //cout<<done[4]<<done[5]<<done[6]<<done[7];
}
