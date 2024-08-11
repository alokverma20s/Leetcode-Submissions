class disjointSet{
    public:
    vector<int> size, parent;
    disjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]= i;
    }
    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_v == ulp_u) return;
        if(size[ulp_v] > size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;
        disjointSet ds(n*m);
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        // vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i =0; i< n; i++){
            for(int j =0; j< m; j++){
                if(grid[i][j] == 0) continue;
                int node = i * m + j;
                // vis[i][j] = 1;
                for(int k =0; k< 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0  && ny < m && grid[nx][ny] == 1){
                        int adjNode = nx * m + ny;
                        ds.unionBySize(node, adjNode);
                        // cout<< ds.size[nx * m + ny]<<endl;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i< n; i++){
            for(int j=0; j<m ;j++){
                if(grid[i][j] == 1) continue;
                int node = i * m + j;
                set<int> component;
                for(int k =0; k< 4; k++){
                    int cnt = 1;
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0  && ny < m && grid[nx][ny] == 1){
                        component.insert(ds.findUParent(nx * m + ny));
                    }
                }
                int cnt =0;
                for(auto it: component) cnt += ds.size[it];
                ans = max(ans, cnt+1);
                    
            }
        }
        for(int cellNo = 0; cellNo< n* n; cellNo++ ) ans = max(ans, ds.size[ds.findUParent(cellNo)]);
        return ans;
    }
};