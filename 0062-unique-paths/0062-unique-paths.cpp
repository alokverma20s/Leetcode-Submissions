class Solution {
    int countPath(int &m, int &n, int x, int y, vector<vector<int>> &dp){
        if(x == m-1 && y == n-1)
            return 1;
        if(x >= m || y >= n) return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = countPath(m, n, x+1, y, dp) + countPath(m, n, x, y+1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n , -1));
        return countPath(m, n, 0, 0, v);
    }
};