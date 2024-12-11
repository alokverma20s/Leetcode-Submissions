class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < nums.size()){
            while(right < nums.size() && nums[right] - nums[left] <= 2*k){
                right++;
            }
            ans = max(ans, right-left);
            left++;
        }
        return ans;
    }
};