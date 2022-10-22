// https://codeforces.com/problemset/problem/1676/G
#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5;
int vis[N];
int subtree_sum[N] , subtree_sum2[N];
// we calculate how many black and white vertices by subree sum and check if both subtree sums for black and white and maintain a count for it
void reset()
{
    for(int i=0  ; i<N ; i++)
    {
        subtree_sum[i]=0;
        subtree_sum2[i]=0;
        vis[i]= 0;
    }
}
void dfs(vector<int> graph2[] , int vertex,string s)
{
    // cout<<s<<"\n";
    vis[vertex] = 1;
    if(s[vertex-1]=='W') subtree_sum[vertex]+=1;
    else if(s[vertex-1]=='B') subtree_sum2[vertex]+=1;
    for(auto child : graph2[vertex])
    {  
        if(vis[child]==1) continue;
        dfs(graph2 , child,s); 
        subtree_sum[vertex] += subtree_sum[child];
        subtree_sum2[vertex] += subtree_sum2[child];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        int n;
        cin>>n;
        int arr[n];
        
        arr[0]=0;
        for(int i=1 ; i<n ; i++) cin>>arr[i];
        string s;
        cin>>s;
        vector<int> graph2[n+1];
        for(int i=1 ; i<n ; i++)
        {
            graph2[arr[i]].push_back(i+1);
            graph2[i+1].push_back(arr[i]);
        }
        dfs(graph2,1,s);
        int cnt = 0;
        for(int i=1 ; i<=n ; i++)
        {
            if(subtree_sum2[i]==subtree_sum[i]) cnt++;
        }
        cout<<cnt<<"\n";
    }
}