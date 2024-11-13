class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // [0,1,4,4,5,7]
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int target1 = lower - nums[i];
            int target2 = upper - nums[i];
            
            auto left = lower_bound(nums.begin()+i+1, nums.end(), target1)- nums.begin();
            auto right = upper_bound(nums.begin()+i+1, nums.end(), target2) - nums.begin();

            ans += (right - left);
        }
        return ans;
    }
};