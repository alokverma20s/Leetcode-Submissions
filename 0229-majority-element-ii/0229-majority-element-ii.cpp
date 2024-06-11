class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt2 = 0, cnt1 = 0, ele1 = INT_MIN, ele2 = INT_MIN, n = nums.size();

        for(int i: nums){
            if(cnt1 == 0 && ele2 != i){
                cnt1++;
                ele1 = i;
            }
            else if(cnt2 == 0 && ele1 != i){
                cnt2++;
                ele2 = i;
            }
            else if(ele1 == i) cnt1++;
            else if(ele2 == i) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(int i: nums){
            if(ele1 == i) cnt1++;
            else if(ele2 == i) cnt2++;
        }
        if(cnt1 > n/3 && cnt2 > n/3) return {ele1, ele2};
        if(cnt1 > n/3 ) return {ele1};
        if(cnt2 > n/3) return {ele2};
        return {};
    }
};