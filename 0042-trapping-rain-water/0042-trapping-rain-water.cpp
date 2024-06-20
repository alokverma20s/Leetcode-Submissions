class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> pre(n, 0), suf(n, 0);

        int temp = 0;
        for(int i=0; i< n; i++){
            temp = max(temp, height[i]);
            pre[i] = temp;
        } 
        temp =0;
        for(int i=n-1; i>=0; i--){
            temp = max(temp, height[i]);
            suf[i] = temp;
        } 
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans + min(suf[i], pre[i]) - height[i];
        }
        return ans;
    }
};