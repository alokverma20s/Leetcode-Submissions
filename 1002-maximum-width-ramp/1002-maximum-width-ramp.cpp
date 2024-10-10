class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());

        int maxi_width = 0;
        int mini = v[0].second;

        for(int i =1; i< n; i++){
            if(v[i].second < mini){
                mini = v[i].second;
            }
            else{
                maxi_width = max(maxi_width, v[i].second - mini);
            }
        }
        return maxi_width;
    }
};