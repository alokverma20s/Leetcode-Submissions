class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0 ; i< n; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int cnt =-1;
        int dirx[] ={1, 0, 0, -1};
        int diry[] ={0, 1, -1, 0};
        while(!q.empty()){
            int size = q.size();
            cnt++;
            for(int i = 0; i< size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int j = 0; j< 4; j++){
                    int nx= x + dirx[j];
                    int ny = y + diry[j];
                    if(nx >=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 1){
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
        }

        for(int i=0 ; i< n; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(cnt == -1)
            return 0;
        return cnt;
    }
};