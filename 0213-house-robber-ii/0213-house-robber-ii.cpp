class Solution {
    int solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int prev = 0, prev2 = 0, cur =0;
        for(int i=0; i<n; i++){
            int take = (i-2 >= 0 ? prev2: 0) + nums[i];
            int notTake = (i-1 >= 0 ? prev : 0);
            cur = max(take, notTake);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++) if(i != 0) temp1.push_back(nums[i]);
        for(int i=0; i<n; i++) if(i != n-1) temp2.push_back(nums[i]);
        return max(solve(temp1), solve(temp2));
    }
};