#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	queue<int> q;
	q.push(a[0]);
	for(int i=1;i<n;i++){
		if(a[i]>q.front()){
			q.push(a[i]);
			q.pop();
		}
		else q.push(a[i]);
	}

	cout<<q.size()<<"\n";

}
