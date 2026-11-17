class Solution {
public: int rec(int tar,int ind,vector<int>&n,vector<vector<int>>&dp){
    if(ind == 0){
        return(tar%n[0]==0);
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notTake = rec(tar,ind-1,n,dp);
    int take = 0;
    if (n[ind]<=tar) take = rec(tar-n[ind],ind,n,dp);
    return dp[ind][tar]= take + notTake;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       
        return rec(amount,coins.size()-1,coins,dp);
    }
};