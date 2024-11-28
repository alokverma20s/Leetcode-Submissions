typedef pair<int, pair<int, int>> ppi; // {distance, {row, col}}
typedef pair<int, int> pii;
class Solution {

    int dijkstra(pii source, int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); // Distance array
        dist[0][0] = 0;

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // Min-heap
        pq.push({0, source}); // {distance, {row, col}}

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentRow = pq.top().second.first;
            int currentCol = pq.top().second.second;
            pq.pop();

            // If the distance is not updated, skip
            if (currentDistance > dist[currentRow][currentCol])
                continue;

            // Traverse adjacent nodes
            int dirX[] = {-1, 0, 1, 0};
            int dirY[] = {0, 1, 0, -1};
            for (int i=0; i< 4; i++) {
                int newX = currentRow+dirX[i];
                int newY = currentCol+dirY[i];
                if(newX < 0 || newX >= n || newY < 0 || newY >= m) 
                    continue;
                int weight = grid[newX][newY];

                // Relaxation step
                if (dist[currentRow][currentCol] + weight < dist[newX][newY]) {
                    dist[newX][newY] = dist[currentRow][currentCol] + weight;
                    pq.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
        return dist[n-1][m-1];
    }

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return dijkstra({0,0}, n, m, grid);
    }
};