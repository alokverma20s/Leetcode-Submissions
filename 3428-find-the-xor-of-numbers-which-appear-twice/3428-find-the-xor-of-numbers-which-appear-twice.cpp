class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> s;
        int ans  = 0;
        for(int i: nums){
            if(s.find(i) == s.end()) s.insert(i);
            else ans ^= i;
        }
        return ans;
    }
};