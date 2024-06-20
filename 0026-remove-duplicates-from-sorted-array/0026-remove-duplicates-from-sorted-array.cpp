class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int pre = -101;
        for(int i=0; i< n; i++){
            if(pre == nums[i])
                continue;
            else{
                pre = nums[i];
                nums[k]= nums[i];
                k++;
            }
        }
        return k;
    }
};