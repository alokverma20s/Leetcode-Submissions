class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2,int i, int j, vector<vector<int>> &memo) {
        int n = nums1.size();
        int m = nums2.size();
        if (i == n || j == m) {
            return INT_MIN;
        }
        
        if (memo[i][j] != INT_MIN) {
            return memo[i][j];
        }
        
        memo[i][j] = max(
            nums1[i] * nums2[j] + max(solve(nums1, nums2, i + 1, j + 1, memo), 0),
            max(solve(nums1, nums2, i + 1, j, memo), solve(nums1, nums2, i, j + 1, memo))
        );
        
        return memo[i][j];
    };
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, INT_MIN));        
        return solve(nums1, nums2, 0, 0, memo);
    }
};