#define fl(i, l, r) for(int i= (l); i< (r); i++)
#define rl(i, l, r) for(int i= (r-1); i>= (l); i--)
#define pb push_back
#define pp pop_back
#define mk make_pair

typedef long long ll;

class Solution {
    vector<vector<int>> manh;

    vector<int> dirx = {1, 0, -1, 0};
    vector<int> diry = {0, 1, 0, -1};
    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int,int>> q;
        fl(i, 0, n){
            fl(j, 0, n){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    manh[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            fl(i, 0, 4){
                int nx = x+dirx[i];
                int ny = y+diry[i];

                if(nx >= 0 && nx <n && ny >= 0 && ny < n && manh[nx][ny] == -1){
                    manh[nx][ny]  = manh[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        priority_queue<vector<int>> pq;
        vector<vector<int>> safe(n, vector<int>(n, INT_MAX));
        pq.push({manh[0][0], 0, 0});
        safe[0][0] = manh[0][0];

        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int safety = pq.top()[0];
            pq.pop();
            if(x == n-1 && y == n-1)
                return safety;
            fl(i, 0, 4){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx >=0 && nx < n && ny >= 0 && ny < n && safe[nx][ny] == INT_MAX){
                    safe[nx][ny] = min(safety, manh[nx][ny]);
                    pq.push({safe[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> temp(n, -1);
        fl(i, 0, n)
            manh.pb(temp);

        bfs(grid);
        return solve(grid);
    }
};