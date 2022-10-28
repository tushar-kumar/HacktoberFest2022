// https://codeforces.com/problemset/problem/1555/C
// Note: the following code gives the maximum possible scores of both the players i.e if Alice focus on maximising her score rather than minimising BOb's score
// and therefore this is quite different from the above mentioned cf question, but still a good one.

#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>arr, int m){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main(){
    int t,m;
    cin>>t;
    while(t--){
        cin>>m;
        vector<vector<int>>arr(2,vector<int>(m));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }
        vector<vector<int>>dp(2,vector<int>(m,0));
        dp[0][m-1] = arr[0][m-1] + arr[1][m-1];
        dp[1][m-1] = arr[1][m-1];
        // Fill dp array by Alice's Path and find Alice's score 
        for(int j = m-2; j >= 0; j--){
            dp[1][j] = arr[1][j] + dp[1][j+1];
            dp[0][j] = max(dp[0][j+1],dp[1][j]);
            dp[0][j] += arr[0][j];
        }
        cout<<"Printing the dp array filled with Alice's Path:\n";
        print(dp,m);
        int AliceScore = dp[0][0];
        arr[0][0] = 0;
        arr[1][m-1] = 0;
        // traverse Alice's path
        int BobScore = 0;
        for(int j = 0; j < m; j++){
            if(dp[0][j+1] > dp[1][j]){
                arr[0][j+1] = 0;
            }
            else{
                // once player goes down only rightwards movement is possible
                for(int index = j; index < m; index++){
                    arr[1][index] = 0;
                }
                break;
            }
        }
        // now we will calculate Bob's score according to updated values
        for(int i = 0; i < m; i++){
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
        dp[0][m-1] = arr[0][m-1] + arr[1][m-1];
        dp[1][m-1] = arr[1][m-1];
        for(int j = m-2; j >= 0; j--){
            dp[1][j] = arr[1][j] + dp[1][j+1];
            dp[0][j] = max(dp[0][j+1],dp[1][j]);
            dp[0][j] += arr[0][j];
        }
        cout<<"Printing the input array filled with Bob's Path:\n";
        print(arr,m);
        cout<<"Printing the dp array filled with Bob's Path:\n";
        print(dp,m);
        BobScore = dp[0][0];
        cout<<BobScore<<"\n";
    }
    return 0;
}