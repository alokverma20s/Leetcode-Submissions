class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i< edges.size(); i++)
            adj[edges[i][1]].push_back(edges[i][0]);

        
        bool found = false;
        int ans= -1, cnt = 0;
        for(int i=0; i< n; i++){
            cout<<adj[i].size()<<" ";
            if(adj[i].size() == 0) {
                ans= i;
                cnt++;
                found = true;
            }
            if(cnt > 1 && found) return -1;
        }
        return ans;

    }
};