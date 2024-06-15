class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int pre = nums[0];
        int ans = 0;
        for(int i: nums){
            if(pre + 1 == i){
                cnt++;
                ans = max(ans, cnt);
            }else if(pre == i) continue;
            else{
                cnt = 0;
            }
            pre = i;
        }
        return ans+1;
    }
};