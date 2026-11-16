class Solution {
public: int rec(int tar,int ind,vector<int>&n,vector<vector<int>>&dp){
    if(ind==0) {
        if (tar%n[ind]==0) return tar/n[0];
        else return 1e9;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notpick = 0+rec(tar,ind-1,n,dp);
    int pick = INT_MAX;
    if(n[ind]<=tar) pick = 1 + rec(tar-n[ind],ind,n,dp);
     return dp[ind][tar]= min(pick,notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = rec(amount,coins.size()-1,coins,dp);
        if (ans>=1e9) return -1;
        return ans;
    }
};