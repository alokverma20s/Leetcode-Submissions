class Solution {
    int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp){
        if(i == nums.size()){
            return 0;
        }

        if(prev != -1e5 && dp[i][prev + 1e4+1] != -1) return dp[i][prev + 1e4+1];

        int take = 0;
        if(prev < nums[i]) take  = solve(nums, i+1, nums[i], dp) + 1;
        int notTake = solve(nums, i+1, prev, dp);

        return ((prev == -1e5)? max(take, notTake) : (dp[i][prev + 1e4+1] = max(take, notTake)));
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2* 1e4 +2, -1));
        return solve(nums, 0, -1e5, dp);
    }
};