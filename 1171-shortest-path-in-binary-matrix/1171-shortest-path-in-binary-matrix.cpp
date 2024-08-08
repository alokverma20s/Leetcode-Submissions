class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = grid.size();


        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        if(grid[0][0] == 0) dist[0][0] = 1;
        else return -1;

        pq.push({1, {0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            for(int i=0; i< 8; i++){
                int x = row + dx[i];
                int y = col + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && wt+1 < dist[x][y]){
                    dist[x][y] = wt + 1;
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];

    }
};