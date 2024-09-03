class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i= 0; i< (1 << n); i++){
            vector<int> temp;
            bitset<10> a(i);
            
            for(int j=0; j< n; j++){
                if(a[j] == 1) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};