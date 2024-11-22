class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> count;

        for (int i = 0; i < m; ++i) {
            string pattern;
            for (int j = 0; j < n; ++j) {
                pattern += (matrix[i][j] == matrix[i][0]) +'0';
            }
            count[pattern]++;
        }

        int maxRows = 0;
        for (auto& [pattern, cnt] : count) {
            maxRows = max(maxRows, cnt);
        }

        return maxRows;
    }
};
