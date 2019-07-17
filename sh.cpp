#include<bits/stdc++.h>
using namespace std;

struct strings
{
 int s;
 int h;
 int index;
 strings(int s,int h,int index):s(s),h(h),index(index){}
};


bool compare (strings const& e1, strings const& e2)
{
       if(e1.h == 0) return true;
       else if (e2.h == 0) return false;
       else if(e1.s == 0) return false;
       else if(e2.s == 0)  return true;
       else return ((float(e1.h)/float(e1.s)) < double(float(e2.h)/float(e2.s))); 

}

//increasing order of 'h'/'s'



int main()
{
  int n;
  cin>>n;
  string sh;
  int cs = 0;
  int ch = 0;
  vector< strings > PQ;
  //priority_queue< strings, vector<strings>,Compare> PQ;
  vector<string> V;
  int v = 0;
  for(int i = 0;i<n;i++)
    {
      cin>>sh;
      for(int j=0;j<sh.size();j++)
          {
             if(sh[j] =='s') cs++;
             else if(sh[j] == 'h') { ch++; v = v + cs; }
          }
      //cout<<cs<<" "<<ch<<"\n";
      
      PQ.push_back(strings(cs,ch,i));
      cs = 0; ch = 0; v = 0;
      V.push_back(sh);
    }


  sort(PQ.begin(),PQ.end(),compare);
 //string final_string = " ";
 long long counts = 0;
 //ch = 0;
 long long final_count = 0;
 for(int i = 0; i<PQ.size(); i++)
  {
     strings top = PQ[i];
     int ind = top.index;
     cout<<V[ind]<<" " <<top.s<<" "<<top.h<<"\n";
     for(int i = 0;i<(top.s+top.h); i++)
        {
           if(V[ind][i]=='s') counts++;
           else final_count = final_count + counts;
        }
   }
 cout<<final_count;
 
}  
