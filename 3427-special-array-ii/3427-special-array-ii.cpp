class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> prefix ={0};
        int cur = 0;

        for(int i=0; i< n-1; i++){
            if(nums[i]%2 == nums[i+1]%2){
                cur++;
            }
            prefix.push_back(cur);
        }
        // prefix.push_back(cur);
        vector<bool> ans;
        for(int i=0; i<q.size(); i++){
            int start = q[i][0];
            int end = q[i][1];
            if(start == end){
                ans.push_back(true);
                // cout<<"reached here ";
                continue;
            }
            if(prefix[start] - prefix[end] == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        // for(int i: prefix)
        //     cout<<i<<" ";
        return ans;
    }
};