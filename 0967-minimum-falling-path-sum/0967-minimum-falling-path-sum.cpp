class Solution {
    int solve(int x, int y, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        int n = matrix.size();
        if (x == n - 1)
            return matrix[x][y];
        if (dp[x][y] != -1)
            return dp[x][y];
        int same = solve(x + 1, y, matrix, dp);
        int left = INT_MAX;
        if (y - 1 >= 0)
            left = solve(x + 1, y - 1, matrix, dp);
        int right = INT_MAX;
        if (y + 1 < n)
            right = solve(x + 1, y + 1, matrix, dp);

        dp[x][y] = min(same, min(left, right)) + matrix[x][y];
        return dp[x][y];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
            dp[n-1][i] = matrix[n-1][i];
        
        for(int i= n-2; i>= 0; i--){
            for(int j=0; j< n; j++){
                int same = dp[i+1][j];
                int left = (j-1 >= 0) ? dp[i+1][j-1]: INT_MAX;
                int right = (j+1 < n) ? dp[i+1][j+1]: INT_MAX;
                dp[i][j] = min(same, min(left, right)) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i= 0; i< n; i++) ans = min(ans, dp[0][i]);
        return ans;
    }
};