#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> num;
  num.push_back(4);
  num.push_back(1);
  num.push_back(3);
  num.push_back(5);
  sort(num.begin(),num.end(),greater<int>());
  num.pop_back();
  cout<<*num.begin();
}
 
