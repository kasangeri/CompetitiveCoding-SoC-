    #include<bits/stdc++.h>
     
    using namespace std;
    const int N = 1000000;
    long long tree[2][N],temp[N],v[N];
    int n;
    long long query(long long tree[], int k)
    {
        long long s = 0;
        while (k>0)
        {
            s+=tree[k];
            k-=k&-k;
            cout<<k<<" ";
        }
        return s;
    }
    void update(long long tree[], int k, int val)
    {
        while (k<=n)
        {
            tree[k]+=val;
            k+=k&-k;
        }
    }
    int main()
    {
        long long s = 0;
        cin >> n;
        for (int i = 1; i<=n; i++)
        {
            cin >> temp[i];
            v[i] = temp[i];
        }
        sort(temp+1,temp+n+1);
        for (int i = 1; i<=n; i++)
        {
            int poz = lower_bound(temp+1,temp+n+1,v[i])-temp;
           // cout<<*temp<<"is the temp here\n";
            v[i] = poz;
            cout<<poz<<"is the poz here\n";
        }
        
        for (int i = 1; i<=n; i++)
        {
            s+=query(tree[1],n)-query(tree[1],v[i]);
            update(tree[0],v[i],1);
            update(tree[1],v[i],query(tree[0],n)-query(tree[0],v[i]));
        }
        cout << s;
    }
