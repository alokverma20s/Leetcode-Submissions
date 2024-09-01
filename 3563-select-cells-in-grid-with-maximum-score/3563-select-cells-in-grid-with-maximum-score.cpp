class Solution {
public:
    int getAns(int dontTakeLesserThanThis, int n, int m, vector<vector<int>>& grid, int bitMask, int maxValOfBitMask, vector<vector<int>>& dp) {
        if (bitMask == maxValOfBitMask) {
            return 0;
        }
        int& x = dp[dontTakeLesserThanThis][bitMask];
        if (x != -1) {
            return x;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curFlag = (1 << i);
            if ((bitMask & curFlag) != 0) {
                continue;
            } else {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] < dontTakeLesserThanThis) {
                        continue;
                    } else {
                        ans = max(ans, grid[i][j] + getAns(grid[i][j] + 1, n, m, grid, (bitMask | curFlag), maxValOfBitMask, dp));
                    }
                }
            }
        }
        return x = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // for (int i = 0; i < n; i++) {
        //     sort(grid[i].begin(), grid[i].end());
        // }
        int bitMask = 0;
        int maxValOfBitMask = (1 << n) - 1;
        vector<vector<int>> dp(110, vector<int>(maxValOfBitMask + 10, -1));
        int ans = getAns(0, n, m, grid, bitMask, maxValOfBitMask, dp);
        return ans;
    }
};