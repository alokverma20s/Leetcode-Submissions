class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rmax(n);
        rmax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(nums[i], rmax[i+1]);
        }
        int i=0, j= 1;
        int ans = 0;
        while(j < n){
            if(nums[i] <= rmax[j]){
                ans = max(ans, j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};