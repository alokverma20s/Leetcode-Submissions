class Solution {
    long long sum;
    bool solve(vector<int> &nums, int i, int cur, int target, vector<vector<int>> &dp){
        if(i == -1) return false;
        if(cur == target){
            return true;
        }

        if(cur > target) return false;
        if(dp[i][cur] != -1) return dp[i][cur];

        int take = solve(nums, i-1, cur + nums[i], target, dp);
        int notTake = solve(nums, i-1, cur, target, dp);
        dp[i][cur] = (take || notTake);
        return dp[i][cur];
    }
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(auto i: nums) sum += i;

        if(sum %2) return false;

        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        
        return solve(nums, n-1, 0, sum/2, dp);
    }
};