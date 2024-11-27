class Solution {
    int shortestPath(vector<vector<int>> &adj, int n){
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int dis = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i< size; i++){
                int cur = q.front();
                q.pop();
                if(cur == n-1) return dis;

                for(int nei: adj[cur]){
                    if(!vis[nei]) vis[nei]= 1, q.push(nei);
                }
            }
            dis++;
        }
        return dis;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0; i< n; i++){
            if(i != n-1)
                adj[i].push_back(i+1);
        }

        vector<int> res;
        for(auto& q: queries){
            adj[q[0]].push_back(q[1]);
            res.push_back(shortestPath(adj, n));
        }
        return res;
    }
};