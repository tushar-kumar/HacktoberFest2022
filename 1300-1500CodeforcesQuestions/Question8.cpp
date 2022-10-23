// https://codeforces.com/problemset/problem/1540/A
#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
#define int long long
const int N = 2e5+5;
const int mod = 1e9+7;
vector<int> graph[N];
vector<int> order;
int vis[N];
void reset()
{
    order.clear();
    for(int i=0 ; i<N ; i++) vis[i] = 0 , graph[i].clear(); // flushing the input of previous test case
}
void dfs(int vertex)
{
    order.push_back(vertex); 
    vis[vertex] = 1;
    for(int child : graph[vertex])
    {
        if(vis[child]) continue;
        dfs(child);
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
        int minimal_cost=0;
        sort(arr,arr+n); // sorting the array
        int sum = 0;
        for(int i=2; i<n ; i++) minimal_cost += arr[i]; // the first solution is to add edges between 1 and i vertices
        sum += arr[1]+minimal_cost;
        for(int i=1 ; i<n-1 ; i++)
        {
            int temp = sum-arr[i+1]; // we'll connected the edges i and i+1 because they will add minimum weight
            int multiplier = (n-i-1); // all the remaining edges will be negative because we have already established a positive path
            minimal_cost += -arr[i]*multiplier+temp;
            sum-=arr[i];
        }
        cout<<(-1)*minimal_cost<<"\n"; // cost will always be negative
    }
}