#include<bits/stdc++.h>
using namespace std;


int A[71];
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int bitmask[71];
int pow2[100000];
long dp[71][(1<<19)+1];
long long count(int num,int mask)
{
  if(num>70 && mask==0) return 1; //perfect square reached
  if(num>70 && mask!=0) return 0;
  int c = dp[num][mask];
  if (c!=-1) {
        return c;
    }
  if(A[num]==0) c = count(num+1, mask)%(1000000007);
  else
     {
       long long yo = pow2[A[num]-1];
       c = yo * count(num+1, mask)%(1000000007);
       c+= yo * count(num+1, mask^bitmask[num])%(1000000007);
     }
  dp[num][mask] = c;
  return c%(1000000007);

}


int main()
{
 int n;
 cin>>n;
 memset(dp, -1, sizeof dp);
 pow2[0]=1;
 for(int k=1;k<100000;k++) pow2[k] = (pow2[k-1])*2 % (1000000007);
 int ele;
 for(int i=0;i<n;i++){cin>>ele; A[ele]+=1;} 
 for(int i=0;i<=70;i++)
  {
    int mask = 0;
    int cur = i;
    for(int j=0;j<19;j++)
    {
      // while(cur!=0) 
          { while(cur%p[j]==0 && cur>0) {mask^=(1<<j); cur = cur/p[j];} }
       
    }
     bitmask[i] = mask;

  }

  cout<<count(1,0)-1<<endl;
  
 
// for(int i=0;i<70;i++)
  //cout<<bitmask[i];
 
 


}
