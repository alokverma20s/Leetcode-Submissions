class Solution {
    int setBit(int n){
        int cnt = 0;
        while(n > 0){
            cnt += n & 1;
            n = n >> 1;
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int maxi = nums[0], prevMax = 0;
        int curSetBit = setBit(nums[0]);

        for(int i=1; i< nums.size(); i++){
            cout<<curSetBit<<" "<< setBit(nums[i])<<" ";
            if(curSetBit == setBit(nums[i])){
                maxi = max(maxi, nums[i]);
                if(prevMax > nums[i]) return false;
            }
            else{
                prevMax = maxi;
                if(prevMax > nums[i]) return false;
                curSetBit = setBit(nums[i]);
                maxi = nums[i];
            }
        }
        return true;
    }
};