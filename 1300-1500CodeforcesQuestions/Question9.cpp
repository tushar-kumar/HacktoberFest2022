    // https://codeforces.com/problemset/problem/1534/C
    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    const int N = 4e5+10;
    const int mod = 1e9+7;

    int parent[N];
    int dsu_size[N];
    int power(int a , int b)
    {
        int res = 1;
        while(b)
        {
            if(b%2) res = (res*a)%mod , b--;
            else a = (a*a)%mod , b/=2;
        }
        return res;
    }
    void make(int v)
    {
        parent[v]=v;
        dsu_size[v]=1;
    }
    int find(int v)
    {
        if(v==parent[v])
        {
            return v;
        }
        return parent[v] = find(parent[v]); // will try to make the shortest path. Path compression. This is because the parent will still remain
        // the same.
    }
    void Union(int a, int b)
    {
        a = find(a); // if the parent is the same implies they are in the same group
        b = find(b); // if the parent is not the same implying they are not in the smae group
        if(a!=b)
        {
            if(dsu_size[a]<dsu_size[b]) swap(a,b); // join the small tree to the large tree    
            parent[b] = a;
            dsu_size[a]+=dsu_size[b];

        }
    }
    main()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n;
            cin>>n;
            for(int i=1 ; i<=n ; i++) make(i);
            int a[n] , b[n] , c[n];
            for(int i=0 ; i<n ; i++) cin>>a[i];
            for(int i=0 ; i<n ; i++) cin>>b[i];
            set<int> parents;
            for(int i=0 ; i<n ; i++)
            {
                if(a[i]!=b[i])
                Union(a[i],b[i]); 
            }
            for(int i=1 ; i<=n ; i++)
            {
                int p = find(i);
                if(dsu_size[p]>1) parents.insert(p); // the parent must be unique and dsu_size must be greater than 1 then only the answer will get affected
            cout<<power(2,parents.size())<<"\n";
        }
    }