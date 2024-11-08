class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> temp;
        int xoor = 0;
        int n = nums.size();
        for(int i=0; i< n; i++){
            xoor ^= nums[i];
            // cout<<xoor<<" ";
            temp.push_back(xoor);
        }
        int value = pow(2, maximumBit)-1;
        // cout<<endl<< value;
        for(int i=0; i< n; i++){
            temp[i] = temp[i] ^ value;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};