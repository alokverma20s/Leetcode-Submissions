class Solution {
    set<vector<int>> ans;
    void solve(vector<int>& candidates,int ind, int target, int sum, vector<int> cur){
        if(ind == candidates.size()){
            if(sum == target)
                ans.insert(cur);
            return;
        }
        solve(candidates, ind+1, target, sum, cur);
        if(sum + candidates[ind] <= target){
            cur.push_back(candidates[ind]);
            solve(candidates, ind, target, sum+candidates[ind], cur);
            solve(candidates, ind+1, target, sum+candidates[ind], cur);
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        solve(candidates, 0, target, 0, cur);
        // return ans;
        vector<vector<int>> v;
        for(auto i: ans)
            v.push_back(i);
        return v;
    }
};