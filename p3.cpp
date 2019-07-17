#include<iostream>
#include<stack>
using namespace std;



int main(){
	string a;
	cin>>a;
	stack<char> Q;
	for(int i=a.size()-1;i>=0;i--){
		if(Q.empty()) Q.push(a[i]);
		else if(a[i]==Q.top()) Q.pop();
		else Q.push(a[i]);
	}
	while(!Q.empty()){
		cout<<Q.top();
		Q.pop();
	}
	cout<<"\n";
	

}