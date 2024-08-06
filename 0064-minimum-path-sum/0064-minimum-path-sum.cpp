class Solution {
    int solve(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(x == n || y == m) return 0;
        if(x == n-1 && y == m-1){
            return grid[x][y];
        }
        if(dp[x][y] != -1) return dp[x][y];

        int down= INT_MAX;
        int right = INT_MAX;
        if(y+1 < m) down = solve(x, y+1, grid, dp) + grid[x][y];
        if(x+1 <n) right = solve(x+1, y, grid, dp) + grid[x][y];

        return dp[x][y] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(0,0, grid, dp);
    }
};