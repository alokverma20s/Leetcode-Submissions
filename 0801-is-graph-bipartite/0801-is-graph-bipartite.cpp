class Solution {
    bool bfs(vector<vector<int>> &graph, int src, vector<int> &color){
        color[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = color[node] == 0 ? 1: 0;
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i= 0; i<graph.size(); i++){
            if(color[i] == -1)
                if(!bfs(graph, i, color)) return false;
        }
        return true;
    }
};