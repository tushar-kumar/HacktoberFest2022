#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        vector<vector<int>>dp(n, vector<int>(n,0));
        int sum = 0;
        if(arr[0] == 0)
        dp[0][0] = 1;
        int val = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(j != 0){
                    val = 0;
                    if(arr[j] == 0) val = 1;
                    dp[i][j] = dp[i][j-1] + val;
                } 
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                sum += (j - i + 1) + dp[i][j];
            }
        }
        cout<<sum<<"\n";
    }
}
// question link: https://codeforces.com/problemset/problem/1637/B
// this is my first question that I solved using dp all by my own🥺❣️