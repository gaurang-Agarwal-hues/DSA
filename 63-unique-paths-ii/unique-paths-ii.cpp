class Solution {
public: int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp) {
    if (i<0 || j<0) return 0;
    if (a[i][j] == 1) return 0;
    if (i==0 && j==0) return 1;
    if (dp[i][j] != -1) return dp[i][j];
   int up = f(i-1,j,a,dp);
   int left = f(i,j-1,a,dp);
    return dp[i][j] = up + left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
       return f(i-1,j-1,obstacleGrid,dp);

    }                                                                                                
};