// https://codeforces.com/problemset/problem/1638/C
#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
#define int long long
const int N = 2e5+5;
const int mod = 1e9+7;
int parent[N];
int dsu_size[N];
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
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++) cin>>arr[i];
        int cc = 0;
        bool is_permutation = false;
        map<int,int> array_tracker;
        // connected components are only when upto number i if all the numbers between numbers 0 to i appear
        for(int i=0 ; i<n ; i++)
        {
            array_tracker[arr[i]]++;
            auto it = array_tracker.begin();
            auto it2 = --array_tracker.end();
            int ele1 = it->first;
            int ele2 = it2->first;
            if(ele1==1 && ele2==i+1) cc++;
        }
        cout<<cc<<"\n";
    }
}