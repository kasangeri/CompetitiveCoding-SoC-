#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s ;
	getline(cin,s);

	stack<char> b;
	b.push('a');
	for(int i=0;i<s.length();i++)
	{
		// cout<<"Here";
		char x = b.top();
		if(s[i]=='['||s[i]=='{' || s[i]=='(')
			{ b.push(s[i]); continue;}
		
		else if(s[i]==']' && x=='[')
			b.pop();
		else if(s[i]==')' && x=='(')
			b.pop();
		else if(s[i]=='}' && x=='{')
			b.pop();		
		else if(b.size()==1)
			{b.push('a');
			break;}
	}
	b.pop();
	if (b.empty())
		cout<<"Balanced\n";
	else
		cout<<"Unbalanced\n";
}