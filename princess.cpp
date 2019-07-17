#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,m;
 cin>>n>>m;
 int total[m+1];
 for(int i=0;i<=m;i++) total[i]=0;
 //int A[100000];
 int T[1000];
 int A[1000];

 A[0] = 0;
 for(int i=0;i<n;i++)
{
 int c;
 //
  
  A[0] = 0;
 cin>>c; 

 for(int i=1;i<=c;i++) cin>>A[i];
 for(int i=1;i<=c;i++) { A[i] = A[i]+A[i-1]; T[i] = 0;}

 for(int i=1;i<=c;i++) 
     { T[i] = 0;
	for(int k=0;k<=i;k++)
		{ 
                  T[i] = max(T[i],A[k]+A[c]-A[c+k-i]);
                }
     }

 for(int i=m;i>=0;i--)
	for(int k=1;k<=c&& k<=i;k++)
		total[i] = max(total[i], total[i-k]+T[k]);
}

 cout<<total[m];
}
