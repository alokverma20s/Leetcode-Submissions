class Solution {
    vector<int> dirX = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> dirY = {0, 0, 1, -1, 1, -1, 1, -1};
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for(int i=1; i<n-1; i++){
            for(int j=1; j < n-1; j++){
                int res =0;
                for(int k=0; k< 8 ; k++){
                    res = max(res, grid[i+dirX[k]][j+dirY[k]]);
                }
                res = max(res, grid[i][j]);
                ans[i-1][j-1] = res;
            }
        }
        return ans;
    }
};