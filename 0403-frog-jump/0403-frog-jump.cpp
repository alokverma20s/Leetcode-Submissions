class Solution {
    int binarySearch(vector<int> &array, int x, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] == x)
                return mid;
            else if (array[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
    return -1;
    }
    bool solve(vector<int> &stones, int idx, int k, vector<vector<int>> &dp){
        if(idx >= stones.size())
            return false;
        if(idx == stones.size()-1)
            return true;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        bool take = false;
        int index = binarySearch(stones, stones[idx]+k, idx, stones.size()-1);
        if(index > idx){
            return dp[idx][k] = (solve(stones, index, k-1, dp)) || solve(stones, index, k, dp) || solve(stones, index, k+1, dp);
        }

        return dp[idx][k] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size()+1, vector<int>(stones.size()+1, -1));
        return solve(stones, 0, 1, dp);
    }
};