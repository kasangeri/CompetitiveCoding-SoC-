#include<bits/stdc++.h>
using namespace std;




int main()
{
  int n;
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

set<int> one;
set<int> two;
set<int> three;


for(int i= 0;i<n;i++)
{
 if(a[i] == 1) one.insert(price[i]);
 else if(a[i] == 2) two.insert(price[i]);
 else if(a[i] == 3) three.insert(price[i]);
 if(b[i] == 1) one.insert(price[i]);
 else if(b[i] == 2) two.insert(price[i]);
 else if(b[i] == 3) three.insert(price[i]);
}


set<int>::iterator it1 = one.begin();
set<int>::iterator it2 = two.begin();
set<int>::iterator it3 = three.begin();
int m;
cin>>m;
int choice;
for(int i= 0;i<m;i++)
{
 cin>>choice;
 int p;
 if(choice == 1) 
 {p = *it1;}
 else if(choice == 2){ p = *it2;}
 else if(choice == 3){ p = *it3;}
 else p = -1;
 one.erase(p); it1 = one.begin(); 
 two.erase(p);  it2 = two.begin();
 three.erase(p);  it3 = three.begin();
 if(p == 0) cout<<"-1"<<" ";
 else cout<<p<<" ";
}

}

  
