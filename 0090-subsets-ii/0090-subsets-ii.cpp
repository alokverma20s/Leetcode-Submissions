class Solution {
    set<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> cur, int i){
        if(i == nums.size()){
            ans.insert(cur);
            return;
        }
        solve(nums, cur, i+1);
        cur.push_back(nums[i]);
        solve(nums, cur, i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        solve(nums, cur, 0);
        vector<vector<int>> v;
        for(auto i: ans)
            v.push_back(i);
        return v;
    }
};