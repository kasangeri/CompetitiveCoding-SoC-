#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	int price[n],a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	cin>>m;

	int buyers[m];

	for(int i=0;i<m;i++){
		cin>>buyers[i];
	}

	int gone[n];

	for(int i=0;i<n;i++){
		gone[i]=0;
	}

	for(int i=0;i<m;i++){

		int index=-1;

		for(int j=0;j<n;j++){
			if(gone[j]!=1){ 
				if(a[j]==buyers[i] || b[j]==buyers[i]){
					if(index==-1){index=j;}
					else{
						if(price[j]<price[index]){index=j;}
					}
				}
				
			}
		}
		if(index!=-1){
			cout<<price[index]<<" ";
			gone[index]=1;
		}
		else cout<<"-1"<<" ";
	}
}