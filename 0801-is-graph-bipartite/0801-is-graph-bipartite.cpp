class Solution {
    bool bfs(vector<vector<int>>& graph, int node, vector<int> &vis){
        vis[node] = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){

            int n = q.front();
            q.pop();

            for(int i=0; i<graph[n].size(); i++){
                if(vis[graph[n][i]] == -1){
                    if(vis[n] ==  1){
                        vis[graph[n][i]]= 0;
                    }
                    else {
                        vis[graph[n][i]]= 1;
                    }
                    q.push(graph[n][i]);
                }
                else if(vis[n] == vis[graph[n][i]]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n ;i++){
            if(vis[i] == -1){
                if(!bfs(graph, i, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};