#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
        //  int n=heights.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,n);
        //previous smaller
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(!s.empty())
            {
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(!s.empty()){
                    ps[i]=s.top();
                }
            }
            s.push(i);
        }
        //next smaller
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(!s.empty()){
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(!s.empty()){
                    ns[i]=s.top();
                }
            }
            s.push(i);
        }
        long long ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            long long x= (long long)(ns[i]-ps[i]-1)*(long long)heights[i];
            ans=max(ans,x);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
