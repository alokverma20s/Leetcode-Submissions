class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xoor = 0;
        int n = nums.size();
        vector<int> temp(n);
        int value = (1 << maximumBit) - 1;
        for(int i=0; i< n; i++){
            xoor ^= nums[i];
            temp[n-1-i] = (~xoor & value);
        }
        return temp;
    }
};