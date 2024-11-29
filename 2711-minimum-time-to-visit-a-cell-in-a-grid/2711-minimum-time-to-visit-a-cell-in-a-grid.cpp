typedef pair<int, pair<int, int>> ppi; // {distance, {row, col}}
typedef pair<int, int> pii;
class Solution {
    int dijkstra(pii source, int n, int m, vector<vector<int>>& grid) {
        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // Min-heap
        pq.push({0, source}); // {distance, {row, col}}

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int currentRow = pq.top().second.first;
            int currentCol = pq.top().second.second;
            if(currentRow == n-1 && currentCol == m-1) return currentTime;
            pq.pop();

            if(vis[currentRow][currentCol]) continue;

            vis[currentRow][currentCol] = true;

            
            for (int i=0; i< 4; i++) {
                int newX = currentRow+dirX[i];
                int newY = currentCol+dirY[i];
                if(newX < 0 || newX >= n || newY < 0 || newY >= m || vis[newX][newY]) 
                    continue;
                
                int cycleType = ((grid[newX][newY] - currentTime) %2 == 0) ? 1: 0;
                pq.push({max(grid[newX][newY]+ cycleType, currentTime+1), {newX, newY}});
            }
        }
        return -1;
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        return dijkstra({0,0}, n, m, grid);
    }
};