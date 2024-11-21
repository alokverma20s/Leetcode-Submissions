class Solution {
    int solve(int i, vector<int> &p, int buy, vector<vector<int>> &dp){
        if(i == p.size()){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];
        int b = INT_MIN;
        int s = INT_MIN;
        if(buy){
            b = solve(i+1, p, 0, dp) - p[i];
        }
        else{
            s= solve(i+1, p, 1, dp) + p[i];
        }
        int skip = solve(i+1, p, buy, dp);
        return dp[i][buy] = max(b, max(s, skip));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, prices, 1, dp);
    }
};