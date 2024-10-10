class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            if(nums[st.top()] > nums[i]){
                st.push(i);
            }
        }

        int i = n-1;
        int ans  =0;
        while(!st.empty() && i >= 0){
            if(nums[i] >= nums[st.top()]){
                ans = max(ans, i-st.top());
                st.pop();
            }
            else i--;
        }
        return ans;
    }
};