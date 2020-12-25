#include<bits/stdc++.h>
using namespace std;

// Given a value N, if we want to make change for N cents, 
// and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
// how many ways can we make the change? The order of coins doesn’t matter.


int coin_change(int N, vector<int> S, int m)
{
	if (N==0) return 1;
	if (N<0) return 0;
	if (m<=0 && N>=1) return 0;

	return coin_change(N-S[m-1],S,m)+coin_change(N,S,m-1);
}

int coin_change_DP(int N, vector<int> S, int m)
{
	int DP[N+1][m+1];
	for(int i=0;i<m+1;i++) {DP[0][i]=1;}
	for(int i=1;i<N+1;i++) {DP[i][0]=0;}
	for(int i=1;i<(N+1);i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(i-S[j-1]>=0)
				DP[i][j]=DP[i-S[j-1]][j]+DP[i][j-1];
			else
				DP[i][j]=DP[i][j-1];
		}
	}
	return DP[N][m];
}

int main()
{

	int N;
	vector<int> S;
	int m;
	cout<<"Enter Total amount: ";
	cin>>N;
	cout<<"Enter number of dominations: ";
	cin>>m;
	int a;
	cout<<"Enter dominations: ";
	for(int i=0;i<m;i++)
	{
		cin>>a;
		S.push_back(a);
	}

	cout<<"Number of ways is (Recur): " <<coin_change(N,S,m);
	cout<<"\nNumber of ways is (DP): " <<coin_change_DP(N,S,m);
}
