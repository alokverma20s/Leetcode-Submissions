class Solution {
    void solve(vector<vector<int>> &ans, vector<int> &nums, int target, int i,  vector<int> &cur){
        if(target == 0){
            ans.push_back(cur);
        }
        for(int ind = i; ind < nums.size(); ind++){
            if(ind != i && nums[ind] == nums[ind-1]) continue;

            if(nums[ind] > target) break;
            cur.push_back(nums[ind]);
            solve(ans, nums, target-nums[ind], ind+1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, nums, target, 0, cur);
        return ans;
    }
};