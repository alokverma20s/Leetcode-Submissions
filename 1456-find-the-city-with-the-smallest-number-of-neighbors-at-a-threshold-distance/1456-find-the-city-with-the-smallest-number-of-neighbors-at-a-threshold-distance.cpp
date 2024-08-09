class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> m(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++) m[i][i] = 0;

        for(auto i: edges){
            int u = i[0], v = i[1], wt = i[2];
            m[u][v] = wt;
            m[v][u] = wt;
        }

        for(int k =0 ; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j< n; j++)
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
        int mincity =n;
        int ans = n;
        for(int i =0; i< n; i++){
            int cnt =0;
            for(int j =0; j< n; j++){
                if(i == j) continue;
                if(m[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(mincity >= cnt) ans = i;
            mincity = min(mincity, cnt);
        }
        return ans;
    }
};