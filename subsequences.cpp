#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
ll tree[15][100009];
ll n, a, k;
ll query(ll idx, ll node){
    ll ret = 0;
    while(idx > 0){
        ret += tree[node][idx];
        idx -= idx&(-idx);
        //cout<<idx<<" ";
    }
    return ret;
}

void update(ll idx, ll val, ll node){
    while(idx <= n+1){
        tree[node][idx] += val;
        idx += idx&(-idx);        
    }
}
int main() {
 
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a;
        update(a, 1, 0);
        for(int j = 1; j <= k; ++j)
         {
            ll b = query(a-1 ,j-1);
            update(a, b, j);
}
    }
    cout << query(n+1, k) << endl;
}
