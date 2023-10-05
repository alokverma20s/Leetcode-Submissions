class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq = nums.size()/3;
        map<int, int> m;
        for(int i=0; i< nums.size(); i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto i: m){
            if(i.second > freq){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};