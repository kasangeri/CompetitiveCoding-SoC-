#include<iostream>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int x=2;
	int l=min(a.size(),b.size());
	for(int i=0;i<l;i++){
		if(tolower(a[i])>tolower(b[i])){
			cout<<"1"<<"\n";
			x=1;
			break;
		}
		else if(tolower(a[i])<tolower(b[i])){
			cout<<"-1"<<"\n";
			x=-1;
			break;
		}
	}
	if(x==2){
		if(a.size()==b.size()){
			cout<<"0"<<"\n";
		}
		else if(a.size()<b.size()){
			cout<<"1"<<"\n";
		}
		else{
			cout<<"-1"<<"\n";
		}
	}
	

}