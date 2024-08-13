class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            int take = (i-2 >= 0 ? dp[i-2]: 0) + nums[i];
            int notTake = (i-1 >= 0 ? dp[i-1] : 0);
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }
};