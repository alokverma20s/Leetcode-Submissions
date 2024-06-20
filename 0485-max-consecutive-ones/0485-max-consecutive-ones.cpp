class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans =0;
        int k =0;

        for(int i: nums){
            if(i == 1) k++;
            else k =0;
            ans = max(ans, k);
        }
        return ans;
    }
};