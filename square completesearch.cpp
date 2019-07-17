#include<bits/stdc++.h>
using namespace std;
int n;

long long a[100000];
int dp[100000][(1<<10)-1];

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 

int countsquares(int index, long long product, long long c)
{
 //cout<<product<<"\n";
 if(index == n) return c%(1000000007);
 if(dp[index][product]!=-1) return dp[index][product];
 long double x = product * a[index];
 if(isPerfectSquare(x)==true){ c=(c+1)%(1000000007); x=1;}
 long long cc = countsquares(index+1,x,c);
 //int cd = countsquares(index+1,product,cc);
 dp[index][product] = (countsquares(index+1,product,cc));
 return dp[index][product];
}

int main()
{

memset(dp,-1,sizeof dp);
cin>>n;
for(int i=0;i<n;i++) cin>>a[i];
//int b[n];
//cout<<check_square(a[0]);

long long x = countsquares(0,1,0);
cout<<x<<"\n";
}
