class Solution {
    int solve(vector<vector<int>>& grid, vector<pair<int, int>> &z, vector<pair<int, int>> &e, int currIndex){
        if(currIndex == z.size())
            return 0;
        int n = e.size();
        int x = z[currIndex].first;
        int y = z[currIndex].second;

        int ans = 100000;
        for(int i =0; i< n; i++){
            int currX = e[i].first;
            int currY = e[i].second;
            if(grid[currX][currY] > 1){
                grid[currX][currY]--;
                grid[x][y] = 1;
                ans = min(ans, abs(currX - x) + abs(currY - y) + solve(grid, z, e , currIndex+1));

                // undo
                grid[currX][currY]++;
                grid[x][y]=0;
            }
        }
        return ans;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> z, e;
        for(int i=0; i<3; i++){
            for(int j=0; j < 3; j++){
                if(grid[i][j]== 0)
                    z.push_back({i, j});
                else if(grid[i][j] > 1)
                    e.push_back({i, j});
                
            }
        }
        return solve(grid, z, e, 0);
    }
};