class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size()-1, low =0,index=-1,mid;
        while(high >= low){
            mid = low+(high-low)/2;
            if(nums[mid] == target){
                index = mid;
                break;
            }
            else if(nums[mid]<target)
                low= mid+1;
            else
                high = mid-1;
        }
        vector<int> ans(2);
        ans = {-1,-1};
        if(index==-1)
            return ans;
        int j= index,k = index;
        while(j<nums.size()-1 && nums[j+1]==target ){
            j++;
        }
        ans[1]=j;
        while(k>0 && nums[k-1]==target ){
            k--;
        }
        ans[0]=k;
        return ans;
    }
};