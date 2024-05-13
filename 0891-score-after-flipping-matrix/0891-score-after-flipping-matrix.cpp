#define fl(i, l, r) for(int i=(l); i< r; i++)
class Solution {
    void toggleRow(vector<vector<int>>& grid, int row){
        int n = grid[0].size();
        fl(i, 0, n){
            grid[row][i] = !grid[row][i];
        }
    }
    void toggleCol(vector<vector<int>>& grid, int col){
        int n = grid.size();
        fl(i, 0, n){
            grid[i][col] = !grid[i][col];
        }
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        fl(i, 0, n){
            if(grid[i][0] == 0){
                toggleRow(grid, i);
            }
        }
        fl(j, 0, m){
            int zeros = 0, ones = 0;
            fl(i, 0, n){
                if(grid[i][j] == 0) zeros++;
                else ones++;
            }
            if(zeros > ones)
                toggleCol(grid, j);
        }
        int ans =0;
        fl(i, 0, n){
            int temp =0;
            fl(j, 0, m){
                temp = temp*2 + grid[i][j];
            }
            ans += temp;
        }
        return ans;
    }
};