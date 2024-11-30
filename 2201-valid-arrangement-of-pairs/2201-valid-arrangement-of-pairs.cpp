class Solution {
    void findEulerPath(vector<int> &eulerPath, unordered_map<int, int> &outdegree, unordered_map<int, vector<int>> &adj, int node){
        while(outdegree[node]){
            outdegree[node]--;
            int nextNode = adj[node][outdegree[node]];
            findEulerPath(eulerPath, outdegree, adj, nextNode);
        }
        eulerPath.push_back(node);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        set<int> nodes;

        for (auto it : pairs) {
            int fi = it[0], se = it[1];
            adj[fi].push_back(se);
            outdegree[fi]++;
            indegree[se]++;
            nodes.insert(fi);
            nodes.insert(se);
        }

        int startNode = INT_MAX;
        for (auto node : nodes) {
            if(outdegree[node] == 1 + indegree[node]){
                startNode= node;
                break;
            }
        }

        if (startNode == INT_MAX) {
            startNode = pairs[0][0];
        }

        vector<vector<int>> ans;

        vector<int> eulerPath;

        findEulerPath(eulerPath, outdegree, adj, startNode);
        reverse(eulerPath.begin(), eulerPath.end());
        for(int i=0; i< eulerPath.size()-1; i++){
            ans.push_back({eulerPath[i], eulerPath[i+1]});
        }
        return ans;
    }
};
