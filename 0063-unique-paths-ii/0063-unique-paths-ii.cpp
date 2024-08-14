class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>prev(m,0);
        if(grid[n-1][m-1] != 1) prev[m-1] = 1;
        for(int i = m-2; i>= 0; i--){
            if(grid[n-1][i] != 1) prev[i] = prev[i+1];
            else prev[i] = 0;
        }
        for(int i= n-2; i >=0; i--){
            vector<long long> cur(m, 0);
            for(int j= m-1; j>=0; j--){
                if(grid[i][j] == 1){
                    cur[j] = 0;
                    continue;
                }
                if(i+1 <n) cur[j] += prev[j];
                if(j+1 <m) cur[j] += cur[j+1];
            }
            prev = cur;
        }
        return prev[0];
    }
};