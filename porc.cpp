#include<bits/stdc++.h>
#define I int
using namespace std;
const I O=(I)1e5;
I n,m,a[O],F[O],V[O];
main()
{cin>>n>>m;
for(I i=1;i<=n;i++)
{
I c;
cin>>c;
for(I j=1;j<=c;j++)scanf("%d",a+j);
for(I j=1;j<=c;j++)a[j]+=a[j-1];
for(I j=1;j<=c;j++)
  for(I k=V[j]=0;k<=j;k++)
    V[j]=max(V[j],a[k]+a[c]-a[c-j+k]);
for(I j=m;j>=0;j--)
  for(I k=1;k<=c&&k<=j;k++)
     F[j]=max(F[j],F[j-k]+V[k]);
}
cout<<F[m];
}
