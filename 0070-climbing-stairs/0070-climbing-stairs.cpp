class Solution {
    int solve(int i, int n, vector<int> &dp){
        if(i == n || i == n-1) return 1;

        if(dp[i] != -1)
            return dp[i];
        dp[i] = solve(i+1, n, dp) + solve(i+2, n, dp);
        return dp[i];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return solve(0, n, dp);
    }
};