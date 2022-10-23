// https://codeforces.com/problemset/problem/1263/D
#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
#define int long long
const int N = 2e5+30;
const int mod = 1e9+7;
vector<int> graph[N];
int vis[N];
void dfs(int vertex)
{
    vis[vertex] = 1;
    for(auto &child : graph[vertex])
    {
        if(vis[child]) continue;
        dfs(child);
    }
}
main()
{
    // this problem can be solved by dsu because ab will be connnected by a and b so there are connections 
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    // cin>>T;
    T = 1;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            string s;
            cin>>s;
            for(auto &ch : s){ graph[ch-'a'].push_back(i+27);
                graph[i+27].push_back(ch-'a');
            }
        }
        int cc = 0; // number of connected components will be the number of unique passwords so we run dfs to calculate connected components
        for(int i=0 ; i<26 ; i++)
        {
            if(vis[i]) continue;
            if(graph[i].size()==0) continue;
            dfs(i);
            cc++;
        }
        cout<<cc<<"\n";
    }
}