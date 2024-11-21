class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(int i=0; i< nums.size(); i++){
            for( int prev = 0 ; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    dp[i] = max(dp[i], (1 + dp[prev]));
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};