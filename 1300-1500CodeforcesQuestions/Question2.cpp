// https://codeforces.com/problemset/problem/1735/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 26;
const int mod = 1e9+7;
int in[26] , out[26];
int parent[N];
int dsu_size[N];
void reset() // flush the previous values
{
    for(int i=0 ; i<26 ; i++)
    {
        in[i] = out[i] = -1;
    }
    for(int i=0 ; i<26 ; i++) parent[i] = dsu_size[i] = 0;
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
void init()
{
    for(int i=0 ; i<26 ; i++) in[i] = out[i]=-1; // initializing with invalid 
}
main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
       reset();
       init();
       int n;
       string s;
       cin>>n;
       cin>>s;
       for(int i=0 ; i<n ; i++)
       {
            for(int j=0 ; j<26 ; j++)
            {
                if(s[i]-'a'==j) continue; // can't transit to itself
                if(in[s[i]-'a']!=-1) break;
                if(out[j]==-1) // only one edge
                {
                    Union(s[i]-'a',j); // make a graph
                    in[s[i]-'a'] = j;
                    out[j] = s[i]-'a';

                    // checking a cycle
                    int ele = j; // starting point is min_ele
                    int cnt = 0; // keeping track of how large our circle is
                    bool inside_loop = false; // done because of single element
                    while(out[ele]!=-1)
                    {
                        ele = out[ele]; // traversing the graph
                        cnt++;
                        inside_loop = true;
                        if(ele==j) break;
                    }

                    if(inside_loop == true && ele==j && cnt<26) // if it is not a single element and a small circle is formed apply anti union
                    {
                        out[j] = -1;
                        in[s[i]-'a'] = -1;
                        parent[j] = 0;
                        dsu_size[s[i]-'a']=0;
                        continue; // we'll see the next element
                    }
                    break; // if the above conditions are true we'll break and our valid graph is formed
                }
            }
       }
       // obtaining the string from the in
        string t = "";
        for(int i=0 ; i<n ; i++)
        {
            t += (char)(97+in[s[i]-'a']);
        }
        cout<<t<<"\n";
    }
}