class Solution {
    int solve(int n, vector<int> &nums, vector<int> &dp){
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take = solve(n-2, nums, dp) + nums[n];
        int notTake = solve(n-1, nums, dp) + 0;

        return dp[n] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++) if(i != 0) temp1.push_back(nums[i]);
        for(int i=0; i<n; i++) if(i != n-1) temp2.push_back(nums[i]);
        int take1 = solve(n-2, temp1, dp1);
        int take2 = solve(n-2, temp2, dp2);
        return max(take1, take2);
    }
};