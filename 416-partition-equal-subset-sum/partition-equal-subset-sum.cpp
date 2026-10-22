class Solution {
public: bool find(int target,int n, vector<int>&a,vector<vector<int>>&dp){
    if (target==0) return true;
   if (n == 0) return a[0] == target;
   if(dp[n][target]!= -1) {
    return dp[n][target];
   }
    bool notTake = find(target,n-1,a,dp);
    bool take = false;
    if(target>=a[n]){
        take = find(target-a[n],n-1,a,dp);
    }
 return dp[n][target] = ( take || notTake);
}
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0;i<nums.size();i++){
            totalSum = totalSum + nums[i];
        }
        int target = totalSum/2;
        if (totalSum % 2 !=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1)); 
        return  find(totalSum/2,nums.size()-1,nums,dp);
    }
};