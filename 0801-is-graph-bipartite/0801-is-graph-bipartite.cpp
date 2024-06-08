class Solution {
    bool dfs(vector<vector<int>>& graph, int node, vector<int> &vis, int color){
        vis[node] = color;

        for( int i: graph[node]){
            if(vis[i] == -1)
                {if( dfs(graph, i, vis, !color) ==  false) return false;}
            else if(vis[i] == color) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n ;i++){
            if(vis[i] == -1)
                {if(!dfs(graph, i, vis, 0)) return false;}
        }
        return true;
    }
};