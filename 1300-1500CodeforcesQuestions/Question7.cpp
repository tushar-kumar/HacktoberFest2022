// https://codeforces.com/problemset/problem/1559/D1
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
int parent[N];
int parent2[N];
int size1[N];
int size12[N];
vector<pair<int,int>> vec;
void make(int v)
{
    parent[v] = v;
    size1[v] = 1;
}
void make2(int v)
{
    parent2[v] = v;
    size12[v] = 1;
}
int find(int v)
{
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
int find2(int v)
{
   if(v==parent2[v]) return v;
    return parent2[v] = find2(parent2[v]);
}
void Union(int a , int b)
{
    a = find(a); 
    b = find(b);
    if(a!=b)
    {
        if(size1[b]>size1[a]) swap(a,b);
        parent[b] = a;
        size1[a] += size1[b];
    }
}
void Union2(int a , int b)
{
    vec.push_back({b,a});
    a = find2(a); 
    b = find2(b);
    if(a!=b)
    {
        if(size12[b]>size12[a]) swap(a,b);
        parent2[b] = a;
        size12[a] += size12[b];
    }
}
int main()
{
    int n;
    cin>>n;
    int m1,m2;
    cin>>m1>>m2;
    for(int i=1 ; i<=n ; i++){ make(i);
    make2(i);
    }
    while(m1--)
    {
        int x,y;
        cin>>x>>y;
        Union(x,y);
    }
    while(m2--)
    {
        int x,y;
        cin>>x>>y;
        Union2(x,y);
    }
    vec.clear();


    for(int i=1 ; i<=n ; i++)
    {
        for(int j=i+1 ; j<=n ; j++)
        {
            if(find(i)!=find(j) && find2(i)!=find2(j)){ // in order to prevent cycle being formed if they are in the same tree
            Union(i,j);
            Union2(i,j);
            }
        }
    }
    cout<<(int)vec.size()<<endl;
    for(auto &path : vec)
    {
        cout<<path.first<<" "<<path.second<<endl;
    }
}