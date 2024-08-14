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
        vector<int> prev(n), cur(n);
        for(int i=0; i<n; i++)
            prev[i] = matrix[n-1][i];
        
        for(int i= n-2; i>= 0; i--){
            cur.resize(n,0);
            for(int j=0; j< n; j++){
                int same = prev[j];
                int left = (j-1 >= 0) ? prev[j-1]: INT_MAX;
                int right = (j+1 < n) ? prev[j+1]: INT_MAX;
                cur[j] = min(same, min(left, right)) + matrix[i][j];
            }
            prev = cur;
        }
        int ans = INT_MAX;
        for(int i= 0; i< n; i++) ans = min(ans, prev[i]);
        return ans;
    }
};