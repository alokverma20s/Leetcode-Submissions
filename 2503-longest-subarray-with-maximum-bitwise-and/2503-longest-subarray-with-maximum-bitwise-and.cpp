class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int m = max_element(nums.begin(), nums.end())-nums.begin();
        int maxi = nums[m];
        int cnt = 0;
        for(int i=m; i< n; i++){
            int len = 0;
            while(i<n && nums[i] == maxi){
                i++;
                len++;
            }
            cnt = max(cnt, len);
        }
        return cnt;
    }
};