#define fl(i, l , r) for(int i= (l); i<r ; i++)
#define pb push_back
#define pp pop_back

const vector<int> dirX = {1, 0, 0, -1};
const vector<int> dirY = {0, 1, -1, 0};
class Solution {
    int maxi = 0;
    void solve(vector<vector<int>> &g, int x, int y, int n, int m, int sum){
        fl(i, 0, 4){
            int nrow = x+dirX[i];
            int ncol = y+dirY[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol <m && g[nrow][ncol] != 0){
                int temp = g[nrow][ncol];
                g[nrow][ncol] = 0;
                sum +=temp;
                maxi = max(sum, maxi);
                solve(g, nrow , ncol, n, m,  sum);
                sum -= temp;
                g[nrow][ncol] = temp;
            }
        }
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> st;
        fl(i, 0, n){
            fl(j, 0, m){
                solve(grid, i, j, n, m , 0);
            }
        }
        return maxi;
    }
};