class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));

        for(int i = 0; i < guards.size(); i++) {
            g[guards[i][0]][guards[i][1]] = 2;
        }
        for(int i = 0; i < walls.size(); i++) {
            g[walls[i][0]][walls[i][1]] = 3;
        }

        int dir[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < guards.size(); i++) {
            for(int d = 0; d < 4; d++) {
                int y = guards[i][0], x = guards[i][1];
                while(true) {
                    x += dir[d];
                    y += dir[d + 1];
                    if(x < 0 || x >= n || y < 0 || y >= m || g[y][x] == 3 || g[y][x] == 2) break;
                    g[y][x] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};
