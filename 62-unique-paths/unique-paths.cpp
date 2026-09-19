class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return gridways(0, 0, m, n, memo);
    }

private:
    int gridways(int i, int j, int m, int n, vector<vector<int>>& memo) {
        
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        
        if (i == m || j == n) {
            return 0;
        }

       
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int rightway = gridways(i, j + 1, m, n, memo);
        int downway = gridways(i + 1, j, m, n, memo);

        memo[i][j] = rightway + downway;

        return memo[i][j];
    }
};