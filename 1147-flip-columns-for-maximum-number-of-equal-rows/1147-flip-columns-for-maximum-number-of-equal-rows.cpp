class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> count;

        for (int i = 0; i < m; ++i) {
            string pattern1, pattern2;
            for (int j = 0; j < n; ++j) {
                pattern1 += matrix[i][j]+'0';
                pattern2 += (!matrix[i][j]) + '0';
            }
            if(count.find(pattern1) != count.end()) count[pattern1]++;
            else count[pattern2]++;
        }

        int maxRows = 0;
        for (auto& [pattern, cnt] : count) {
            maxRows = max(maxRows, cnt);
        }

        return maxRows;
    }
};
