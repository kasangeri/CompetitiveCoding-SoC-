#include<bits/stdc++.h>
using namespace std;

vector<int> box;
vector<int>::iterator it, m;


int main()
{
 int n;
 cin>>n;
 int reorder = 0;
 int curr = 1;
 int a[n];
 int k = 0;
 int inorder;
 int state = 0;
 for(int i=0;i<2*n;i++)
  {
    string str;
    cin>>str;
    int e;
   if(str == "add")
    {
      cin>>e;
      k++;
      box.push_back(e);
      state = 0;
    }
   else if(str == "remove") 
    {    
      if(curr == box[k-1]) 
        {
          //cout<<boxes.top()<<" "<<curr<<endl;
          box.pop_back(); 
          curr = curr + 1;
          k--;
 
         
        }
      else 
        { 
          int min = INT_MAX;
          m = box.begin();
           //sort(box.begin(),box.end(),greater<int>());
          for(it = box.begin();it!=box.end();it++)
              {
                if(*it < min){ m = it; min = *it;}
               }
          box.erase(m);
          box.push_back(min);
          reorder = reorder + 1; 
          state = 1;
          //cout<<boxes.top()<<endl;
          box.pop_back();
          k--;
          curr = curr + 1; 
        }
    }
  }

 cout<<reorder<<" "; 

}
  
