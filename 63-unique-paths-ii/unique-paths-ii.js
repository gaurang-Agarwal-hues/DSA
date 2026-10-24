/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    const m = obstacleGrid.length, n = obstacleGrid[0].length;

    if(obstacleGrid[0][0]) return 0;

    const dp = new Array(n).fill(0);

    dp[0] = 1;

    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(obstacleGrid[i][j] === 1){
                dp[j] = 0;
            } else if(j > 0){
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }

    return dp[n - 1];
};