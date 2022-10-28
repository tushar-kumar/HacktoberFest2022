#include<iostream>
using namespace std;
//given 2*n floor and 2*1 tiles (infinite), count the no.of ways to tile the floor
int tiling2_1(int n){
    // this turns out to be a fibonacci sequence
    // f(n) = f(n-1) + f(n-2)
    if(n > 0 && n <= 3) return n; 
    if(n<=0) return 0;
    int prev1 = 3;
    int prev2 = 2;
    for(int i = 4; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
//n*m floor and m*1 tiles (infinite)
int tilingM_1(int n, int m){
    // recurrence relation: f(n) = f(n-1) + f(n-m)
    //base case n < m , no of ways = 1 (floor = 1*m and tile 1*m so one way only)
    if(n<m) return 1;
    int dp[n+1];
    dp[m] = 2;
    for(int i = 0; i<m; i++){
        dp[i] = 1;
    }
    for(int i = m+1; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-m];
    }
    return dp[n];
}
int main(){
    int n;
    cout<<tiling2_1(5)<<"\n";
    cout<<tilingM_1(5,3)<<"\n";
}