class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i< n; i++){
            if(dq.empty()) dq.push_front(i);
            else if(nums[dq.front()] > nums[i]){
                dq.push_front(i);
            }
            else{
                while(!dq.empty() && nums[dq.front()] <= nums[i]){
                    dq.pop_front();
                }
                dq.push_front(i);
            }
            if(i- dq.back() >= k) dq.pop_back();
            if(i >= k-1) ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};