class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int increasing = 0;
        int decreasing = 0;

        for(int i=1; i< nums.size(); i++){
            if(nums[i-1] <= nums[i])
                increasing++;
            if(nums[i-1] >= nums[i])
                decreasing++;
        }

        if(increasing == nums.size()-1 || decreasing == nums.size()-1)
            return true;
        return false;

    }
};