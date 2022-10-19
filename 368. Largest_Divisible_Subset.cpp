class Solution {
public:
    
//     int solve(int i,int n,vector<int> &nums,int last){
        
//         if(i>=n) return 0;
//         if(last==-1 || nums[i]%nums[last]==0 || nums[last]%nums[i]==0){
//             int a = solve(i+1,n,nums,i)+ 1;
//             int b = solve(i+1,n,nums,last) ;
//             return max(a,b);
//         }else return solve(i+1,n,nums,last);
        
//     }
    
   vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // return solve(0,n,nums,-1);
       sort(nums.begin(),nums.end());
        int dp[n],hash[n];
        memset(hash,-1,sizeof(hash));
        // memset(dp,1,sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<n;i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                    if(dp[i]<dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
                
            }
           
           
        }
        int ans = 0,index = -1;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<" ";
            if(ans<dp[i]) {
                ans = dp[i];
                index = i;
            }
        }
        // cout<<endl;
        // cout<<ans<<endl;
        vector<int> lds;
        while(index>=0){
            // cout<<index<<" ";
            lds.push_back(nums[index]);
            index = hash[index];
        }
        // cout<<endl;
        // reverse(lds.begin(),lds.end());
        return lds;
    }
};
