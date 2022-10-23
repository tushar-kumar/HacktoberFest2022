// https://codeforces.com/problemset/problem/1711/B

#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
#define int long long
const int N = 2e5+5;
const int mod = 1e9+7;
main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        // reset();
        int n,m;
        cin>>n>>m;
        int edges[n+1] = {0};
        int arr[n+1];
        for(int i=0 ; i<n ; i++) cin>>arr[i];
        int edge_1[m] , edge_2[m];
        int j = 0;
        int m2 = m;
        while(m--)
        {
            cin>>edge_1[j]>>edge_2[j];
            int x = edge_1[j];
            int y = edge_2[j];
            edges[x]++;
            edges[y]++; // keeping track of the edges
            j++;
        }
        if(m2%2==0) cout<<"0\n";
        else{
        int min_happiness = INT_MAX; // initializing with a max value possible
        for(int i=1 ; i<=n ; i++)
        {
            if(edges[i]%2==1) min_happiness = min(min_happiness,arr[i-1]); // adding unhappiness of odd vertices because removing one odd vertices will make the no. of edges even
        }
        for(int i=0 ; i<m2; i++)
        {
            if(edges[edge_1[i]]%2==0 && edges[edge_2[i]]%2==0)
            {
                min_happiness = min(min_happiness ,arr[edge_1[i]-1]+arr[edge_2[i]-1]); // if the even vertices are connected with each other then removing them will resulting in odd edges being removed which will cause even edges
            }
        }
        cout<<min_happiness<<"\n";
        }
    }
}