/* LCS Problem Statement: Given two sequences, 
find the length of longest subsequence present in both of them.
 A subsequence is a sequence that appears in the same relative order, 
 but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. 
 etc are subsequences of “abcdefg”. */

#include<bits/stdc++.h>
using namespace std;


int main()
{
	string A,B;
	cout<<"Enter the strings\n";
	cin>>A>>B;
	int n = A.length();
	int m = B.length();
	int DP[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0) DP[i][j]=0;

			else if(A[i-1]==B[j-1])
				DP[i][j]=DP[i-1][j-1]+1;
			else 
				DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
		}
	}
	cout<<" Length of Largest subsequence is" << DP[n][m];
}