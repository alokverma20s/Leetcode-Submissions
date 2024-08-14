class Solution {
    int solve(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(x == n-1 && y == m-1 && grid[x][y] != 1) return 1;
        if(grid[x][y] == 1){
            dp[x][y] = 0;
            return 0;
        }

        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        if(x+1 < n) dp[x][y] += solve(x+1, y, grid, dp);
        if(y+1 < m) dp[x][y] += solve(x, y+1, grid, dp);

        return dp[x][y];

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0,0, grid, dp);
    }
};