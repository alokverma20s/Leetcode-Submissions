class Solution {
    int ans = 0;
    void subset(vector<int> &nums, int i, vector<int> sub){
        // cout<< i<<" ";
        if(i == nums.size()){
            // cout<<i<<" ";
            int temp =0;
            for(int j=0; j<sub.size(); j++){
                temp = temp ^ sub[j];
                // cout<< sub[j]<<" ";
            }
            // cout<<endl;
            ans += temp;
            return;
        }
        if(i<nums.size()){
            sub.push_back(nums[i]);
            subset(nums, i+1, sub);
            sub.pop_back();
        }
        subset(nums, i+1, sub);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> sub;
        subset(nums, 0, sub);
        return ans;
    }
};