class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0; 
        for(int i: nums)
            target+= i;
        target-= x;
        int l =0;
        int curr_sum =0;
        int max_window = -1;
        for(int r =0; r< nums.size(); r++){
            curr_sum += nums[r];
            while(l <= r && curr_sum > target){
                curr_sum -= nums[l];
                l++;
            }

            if(curr_sum == target)
                max_window = max(max_window, r-l+1);
        }

        return max_window == -1 ? -1 : nums.size() - max_window;
    }
};